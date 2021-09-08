#include "Transform.h"

Transform::Transform()
{

}
glm::vec3 Transform::GetPosition()
{
	return position;
}

void Transform::SetPosition(glm::vec3 pos)
{
	position = pos;
}

glm::vec3 Transform::GetScale()
{
	return scale;
}

void Transform::SetScale(glm::vec3 scale)
{
	this->scale = scale;
}

glm::mat4 Transform::GetTransform()
{
	glm::mat4 model = glm::mat4(1);
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
	model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
	return model;
}

void Transform::SetRotation(glm::vec3 rot){
	rotation = rot;
}
glm::vec3 Transform::GetRotation(){
	return rotation;
}