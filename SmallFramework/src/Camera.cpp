#include "Camera.h"
#include <ext/matrix_transform.hpp>

Camera::Camera()
{
	
}

void Camera::InitCam(glm::mat4 view)
{
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDir = glm::normalize(cameraPos - cameraTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDir));
	glm::vec3 cameraUp = glm::cross(cameraDir, cameraRight);
	
	const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camY = cos(glfwGetTime()) * radius;
	
	view = glm::lookAt(glm::vec3(camX, 0.0, camY), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

}
