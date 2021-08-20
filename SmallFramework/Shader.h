#pragma once
#include <string>
#include <GL\glew.h>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	unsigned int shaderProgram;
	std::string ReadFile(const std::string &path);
	void Compile(const std::string &vertex,const std::string &fragment);
	std::map<std::string, int> uniforms;
	int GetUniformId(std::string variable);
public:
	Shader();
	void CreateShader(const std::string& vertexPath, const std::string& fragmentPath);
	unsigned int GetShaderProgram();
	void Use();	
	void SetUniform(std::string variable, glm::mat4 matrix);
	void SetUniform(std::string variable, glm::vec3 vector);

};

