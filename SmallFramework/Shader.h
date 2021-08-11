#pragma once
#include <string>
#include <GL\glew.h>

class Shader
{
private:
	unsigned int shaderProgram;
	std::string ReadFile(const std::string &path);
	void Compile(const std::string &vertex,const std::string &fragment);

public:
	Shader();
	void CreateShader(const std::string& vertexPath, const std::string& fragmentPath);
	unsigned int GetShaderProgram();
	void Use();

};

