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
#include "Camera.h"
#include <iostream>

WeaponModel::WeaponModel()
	: shader(nullptr)
	, texture(nullptr)
	, vertexArrayID(0)
	, transform()
	, numTriangles(0)
{
}

WeaponModel::~WeaponModel()
{
	glDeleteBuffers(1, &vertexBuffer);
	//glDeleteVertexArrays(1, &vertexArrayID);
	delete shader;
	delete texture;

	//-------------------
	glDeleteBuffers(1, &normalBuffer);
	glDeleteBuffers(1, &texBuffer);

}

bool WeaponModel::loadFromOBJ(const char* fileName)
{
	FILE* f = fopen(fileName, "rt");
	
	if (!f)
	{
		printf("error: no such file: %s", fileName);
		return false;
	}
	
	vertices.push_back(glm::vec3(0, 0, 0));
	uvs.push_back(glm::vec2(0, 0));
	normals.push_back(glm::vec3(0, 0, 0));
	//hasNormals = false;
	
	
	char line[2048];
	
	while (fgets(line, sizeof(line), f))
	{
		if (line[0] == '#') continue;
		
		std::vector<std::string> tokens = Util::tokenize(std::string(line));
		
		if (tokens.empty()) continue;
		
		// v line - a vertex definition
		if (tokens[0] == "v")
		{
			vertices.push_back(glm::vec3(Util::parseToDouble(tokens[1]),
										 Util::parseToDouble(tokens[2]),
										 Util::parseToDouble(tokens[3])));
			continue;
		}

		// vn line - a vertex normal definition
		if (tokens[0] == "vn")
		{
			//hasNormals = true;
			normals.push_back(glm::vec3(Util::parseToDouble(tokens[1]),
										Util::parseToDouble(tokens[2]),
										Util::parseToDouble(tokens[3])));
			continue;
		}

		// vt line - a texture coordinate definition
		if (tokens[0] == "vt")
		{
			uvs.push_back(glm::vec2(Util::parseToDouble(tokens[1]),
									Util::parseToDouble(tokens[2])));
			continue;
		}
		
		// f line - a face definition
		if (tokens[0] == "f")
		{
			numTriangles = tokens.size() - 3;
		}
	}

	
	//uvs.push_back(glm::vec2(0, 0));
	//normals.push_back(glm::vec3(0, 0, 0));*/
	////hasNormals = false;
	//vertices.push_back(0);
	//vertices.push_back(0);
	//vertices.push_back(0);
	//uvs.push_back(0);
	//uvs.push_back(0);
	//normals.push_back(0);
	//normals.push_back(0);
	//normals.push_back(0);
	//
	//char line[2048];
	//
	//while (fgets(line, sizeof(line), f))
	//{
	//	if (line[0] == '#') continue;
	//	
	//	std::vector<std::string> tokens = Util::tokenize(std::string(line));
	//	
	//	if (tokens.empty()) continue;
	//	
	//	// v line - a vertex definition
	//	if (tokens[0] == "v")
	//	{
	//		vertices.push_back(Util::parseToDouble(tokens[1]));
	//		vertices.push_back(Util::parseToDouble(tokens[2]));
	//		vertices.push_back(Util::parseToDouble(tokens[3]));

	//		continue;
	//	}

	//	// vn line - a vertex normal definition
	//	if (tokens[0] == "vn")
	//	{
	//		//hasNormals = true;
	//		normals.push_back(Util::parseToDouble(tokens[1]));
	//		normals.push_back(Util::parseToDouble(tokens[2]));
	//		normals.push_back(Util::parseToDouble(tokens[3]));

	//		continue;
	//	}

	//	// vt line - a texture coordinate definition
	//	if (tokens[0] == "vt")
	//	{
	//		uvs.push_back(Util::parseToDouble(tokens[1]));
	//		uvs.push_back(Util::parseToDouble(tokens[2]));

	//		continue;
	//	}
	//	
	//	// f line - a face definition
	//	if (tokens[0] == "f")
	//	{
	//		++numTriangles;
	//	}
	//}

	return true;
}

bool WeaponModel::loadOBJ(
	const char * path, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals
){
	printf("Loading OBJ file %s...\n", path);

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices; 
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;


	FILE * file = fopen(path, "r");
	if( file == NULL ){
		printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
		return false;
	}

	while( 1 ){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		
		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "vt" ) == 0 ){
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y );
			uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv);
		}else if ( strcmp( lineHeader, "vn" ) == 0 ){
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
			temp_normals.push_back(normal);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices    .push_back(uvIndex[0]);
			uvIndices    .push_back(uvIndex[1]);
			uvIndices    .push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}else{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}

	// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
		glm::vec2 uv = temp_uvs[ uvIndex-1 ];
		glm::vec3 normal = temp_normals[ normalIndex-1 ];
		
		// Put the attributes in buffers
		out_vertices.push_back(vertex);
		out_uvs     .push_back(uv);
		out_normals .push_back(normal);
	
	}

	return true;
}

void WeaponModel::prepareMaterial()
{
	//----CUSTOM LOADER------------------------
	//glGenVertexArrays(1, &vertexArrayID);
	//glBindVertexArray(vertexArrayID);

	//loadFromOBJ("ak.obj");

	loadOBJ("ak.obj", vertices, uvs, normals);

	shader = new GPUProgram;
	shader->loadFragmentShaderFromFile("SimpleColor.frag");
	shader->loadVertexShaderFromFile("weaponModel.vert");
	shader->link();
	
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &texBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs, GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals, GL_STATIC_DRAW);

	//glGenBuffers(1, &vertexBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(double), &vertices, GL_STATIC_DRAW);

	//glGenBuffers(1, &texBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	//glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(double), &uvs, GL_STATIC_DRAW);

	//glGenBuffers(1, &normalBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	//glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(double), &normals, GL_STATIC_DRAW);

	//transform = glm::scale(glm::mat4(), glm::vec3(0.2, 0.2, 0.2));
	
	//----END CUSTOM LOADER--------------------


	//------------DEFAULT--------------------------
	//glGenVertexArrays(1, &vertexArrayID);
	//glBindVertexArray(vertexArrayID);

	//texture = new Texture;
	//texture->loadTexture("test.png");

	//shader = new GPUProgram;

	//shader->loadFragmentShaderFromFile("SimpleTexture.frag");
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

	//------ASSIMP---------------------------------------------------------------------
	//glGenVertexArrays(1, &vertexArrayID);
	//glBindVertexArray(vertexArrayID);
	//shader = new GPUProgram;
	//shader->loadFragmentShaderFromFile("weaponModel.frag");
	//shader->loadVertexShaderFromFile("weaponModel.vert");
	//shader->link();

	//Assimp::Importer importer;
	//const aiScene* scene = importer.ReadFile("ak.obj", aiProcessPreset_TargetRealtime_MaxQuality);

	//aiMesh* mesh = scene->mMeshes[0]; //assuming you only want the first mesh

	//numTriangles = mesh->mNumFaces*3;
	//int index = 0;
	//numUvCoords = mesh->GetNumUVChannels();
 //
	//vertexArray = new float[mesh->mNumFaces*3*3];
	//normalArray = new float[mesh->mNumFaces*3*3];
	//uvArray = new float[mesh->mNumFaces*3*2];
 //
	//for(unsigned int i = 0; i < mesh->mNumFaces; i++)
	//{
	//	const aiFace& face = mesh->mFaces[i];
 //
	//	//foreach index
	//	for(int j = 0; j < 3; j++)//assume all faces are triangulated
	//	{
	//		aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
	//		memcpy(uvArray,&uv,sizeof(float)*2);
	//		uvArray+=2;
 //
	//		aiVector3D normal = mesh->mNormals[face.mIndices[j]];
	//		memcpy(normalArray,&normal,sizeof(float)*3);
	//		normalArray+=3;
 //
	//		aiVector3D pos = mesh->mVertices[face.mIndices[j]];
	//		memcpy(vertexArray,&pos,sizeof(float)*3);
	//		vertexArray+=3;
	//	}
	//}
 //
	//uvArray -= mesh->mNumFaces*3*2;
	//normalArray -= mesh->mNumFaces*3*3;
	//vertexArray -= mesh->mNumFaces*3*3;

	//glGenBuffers(1, &vertexBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray)/sizeof(float), vertexArray, GL_STATIC_DRAW);

	//glGenBuffers(1, &texBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(uvArray)/sizeof(float), uvArray, GL_STATIC_DRAW);

	//glGenBuffers(1, &normalBuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(normalArray)/sizeof(float), normalArray, GL_STATIC_DRAW);
}

void WeaponModel::drawWeapon(Camera& world)
{
	/*shader->use();

	shader->setUniform("model", transform);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(texture->getTexType(), texture->getTexID());

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE,  5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

	glDrawArrays(GL_TRIANGLES, 0, 6);*/

	//---------------------------------------------------------------------------
	shader->use();
	shader->setUniform("camera", world.matrix());
	shader->setUniform("model", transform);
	shader->setUniform("m_color", glm::vec4(1.0, 0.5, 0.0, 0.0));

	// verteces
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	// UV
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,  0, NULL);

	//normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE,  0, NULL);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	//// verteces
	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	//// UV
	//glEnableVertexAttribArray(1);
	//glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	////normals
	//glEnableVertexAttribArray(2);
	//glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, 0, NULL);

	//glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}