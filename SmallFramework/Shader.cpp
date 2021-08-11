#include "Shader.h"

#include <fstream>

std::string Shader::ReadFile(const std::string &path)
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

Shader::Shader():shaderProgram(0) 
{

}

void Shader::Compile(const std::string& vertex, const std::string& fragment)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, (const GLchar* const*)vertex.c_str(), NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, (const GLchar* const*)fragment.c_str(), NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::CreateShader(const std::string& vertexPath, const std::string& fragmentPath) 
{
    std::string vertexShader = ReadFile(vertexPath);
    std::string fragmentShader = ReadFile(fragmentPath);

    Compile(vertexShader, fragmentShader);
}

unsigned int Shader::GetShaderProgram()
{
    return shaderProgram;
}

void Shader::Use(){
    glUseProgram(shaderProgram);
}