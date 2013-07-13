#include <GL\glew.h>
#include <GL\glfw.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <vector>
#include <assimp\Importer.hpp>
#include <assimp\cimport.h>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "GPUProgram.h"
#include "Texture.h"
#include "WeaponModel.h"
#include "Util.h"

WeaponModel::WeaponModel()
	: shader(nullptr)
//	, texture(nullptr)
	, vertexArrayID(0)
	, transform()
{
}

WeaponModel::~WeaponModel()
{
	/*glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
	delete texture;*/
}

void WeaponModel::prepareMaterial()
{
	//glGenVertexArrays(1, &vertexArrayID);
	//glBindVertexArray(vertexArrayID);

	texture = new Texture;
	texture->loadTexture("cs.bmp");

	//shader = new GPUProgram;

	//shader->loadFragmentShaderFromFile("weaponModel.frag");
	//shader->loadVertexShaderFromFile("weaponModel.vert");

	//shader->link();

	//GLfloat vertexBufferData[] = {
	////     X     Y    Z       U    V
	//	0.01, 0.10, 0.0,	1.0, 1.0, /*0.0, 0.0,*/ 
	//	0.01, 0.20, 0.0,	1.0, 0.0, /*0.0, 1.0,*/ 
	//	0.30, 0.20, 0.0,	0.0, 0.0, /*1.0, 1.0,*/ 

	//	0.01, 0.10, 0.0,	1.0, 1.0, /*0.0, 0.0,*/ 
	//	0.30, 0.20, 0.0,	0.0, 0.0, /*1.0, 1.0,*/ 
	//	0.30, 0.10, 0.0,	0.0, 1.0  /*1.0, 0.0*/ 
	//};

	//glGenBuffers(1, &vertexBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	//shader->setUniform("tex", *texture);
	//
	//transform = Util::translate(-1.1, -2.0, 0.0) * Util::scale(4.0, 10.0, 0.0);

	//------------------------------------------------------------------------------------------------
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	shader = new GPUProgram;
	shader->loadFragmentShaderFromFile("weaponModel.frag");
	shader->loadVertexShaderFromFile("weaponModel.vert");
	shader->link();
	shader->setUniform("tex", *texture);

	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile("ak.obj", aiProcessPreset_TargetRealtime_MaxQuality);

	aiMesh* mesh = scene->mMeshes[0]; //assuming you only want the first mesh

	numTriangles = mesh->mNumFaces*3;
	int index = 0;
	numUvCoords = mesh->GetNumUVChannels();
 
	vertexArray = new float[mesh->mNumFaces*3*3];
	normalArray = new float[mesh->mNumFaces*3*3];
	uvArray = new float[mesh->mNumFaces*3*2];
 
	for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		const aiFace& face = mesh->mFaces[i];
 
		//foreach index
		for(int j = 0; j < 3; j++)//assume all faces are triangulated
		{
			aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
			memcpy(uvArray,&uv,sizeof(float)*2);
			uvArray+=2;
 
			aiVector3D normal = mesh->mNormals[face.mIndices[j]];
			memcpy(normalArray,&normal,sizeof(float)*3);
			normalArray+=3;
 
			aiVector3D pos = mesh->mVertices[face.mIndices[j]];
			memcpy(vertexArray,&pos,sizeof(float)*3);
			vertexArray+=3;
		}
	}
 
	uvArray -= mesh->mNumFaces*3*2;
	normalArray -= mesh->mNumFaces*3*3;
	vertexArray -= mesh->mNumFaces*3*3;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

	glGenBuffers(1, &texBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvArray), uvArray, GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalArray), normalArray, GL_STATIC_DRAW);
}

void WeaponModel::drawWeapon()
{
	/*shader->use();

	shader->setUniform("model", transform);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE,  5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

	glDrawArrays(GL_TRIANGLES, 0, 6);*/

	//---------------------------------------------------------------------------
	shader->use();
	shader->setUniform("model", transform);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(texture->getTexType(), texture->getTexID());

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE,  0, NULL);


	glDrawArrays(GL_TRIANGLES, 0, numTriangles);
}