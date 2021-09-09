#pragma once
#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Object.h"

class Transform 
{
private:
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;
public:
	Transform();
	Transform(glm::vec3 pos, glm::vec3 scale, glm::vec3 rot);
	glm::vec3 GetPosition();
	void SetPosition(glm::vec3 pos);
	glm::vec3 GetScale();
	void SetScale(glm::vec3 scale);
	glm::mat4 GetTransform();
	void SetRotation(glm::vec3 rot);
	glm::vec3 GetRotation();
	
};

