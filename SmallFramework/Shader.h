#pragma once
#include <string>

class Shader
{
public:
	std::string ReadFile(const char* path);
	void Compile(const std::string &vertex,const std::string &fragment);

};

