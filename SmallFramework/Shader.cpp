#include "Shader.h"
#include <fstream>

std::string Shader::ReadFile(const char* path)
{
	std::ifstream file(path, std::ios::in);
	std::string line;
	std::string content;

	while (std::getline(file, line))
	{
		content.append(line+"\n");
	}
	return content;
}

void Shader::Compile(const std::string& vertex, const std::string& fragment){

}