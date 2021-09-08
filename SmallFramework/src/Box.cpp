#include "Box.h"

Box::Box()
{
    vertex = {
         -1.0, -1.0,  1.0,0.0,0.0,1.0,1.0f, 1.0f,0.0,0.0,1.0,
         1.0, -1.0,  1.0,0.0,1.0,0.0,1.0f, 0.0f,0.0,0.0,1.0,
        1.0,  1.0,  1.0,0.0,0.0,1.0,0.0f, 0.0f,0.0,0.0,1.0,
        -1.0,  1.0,  1.0,0.0,1.0,0.0,0.0f, 1.0f,0.0,0.0,1.0,
         -1.0, -1.0, -1.0,1.0,0.0,.0,1.0f, 1.0f,0.0,0.0,1.0,
        1.0, -1.0, -1.0,1.0,0.0,0.0,1.0f, 0.0f,0.0,0.0,1.0,
         1.0,  1.0, -1.0,1.0,0.0,0.0,0.0f, 0.0f,0.0,0.0,1.0,
        -1.0,  1.0, -1.0,1.0,0.0,0.0,0.0f, 1.0f,0.0,0.0,1.0
    };

    index = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
    };
	transform.SetPosition(glm::vec3(1, 1, 1));
	transform.SetRotation(glm::vec3(0,0, 0));
	transform.SetScale(glm::vec3(2, 2, 2));
}

void Box::Load()
{
    CreateBuffers();
    texture.Load("assets/textures/tex.png");
}

void Box::Draw(Shader * shader)
{
	alpha += 0.01;
	transform.SetPosition(glm::vec3(alpha, 1, 1));
	transform.SetRotation(glm::vec3(alpha, 1, alpha));
    texture.Use();
    Model::Draw(shader);
}