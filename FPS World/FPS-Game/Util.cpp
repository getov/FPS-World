#include "Util.h"
#include <fstream>

namespace Util
{
	char* loadFile(const char* fileName, size_t* outFileSize)
	{
		std::ifstream file(fileName, std::ios::in | std::ios::binary);

		if (!file.is_open())
		{
			return nullptr;
		}

		std::streamoff begin = file.tellg();
		file.seekg(0, std::ios::end);
		size_t fileSize = size_t(file.tellg() - begin);
		file.seekg(0, std::ios::beg);

		char* fileContents = new char[fileSize + 1];

		file.read(fileContents, fileSize);

		fileContents[fileSize] = 0;

		if (outFileSize)
		{
			*outFileSize = fileSize;
		}

		return fileContents;
	}
}