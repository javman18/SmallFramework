#pragma once
#include "GameState.h"
#include "Plane.h"
#include "Box.h"
#include "Shader.h"
#include "Camera.h"
#include "Platform.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <memory>
#include <list>

class Game : public GameState
{
private:
	glm::mat4 model;
	glm::mat4 view;
	glm::vec3 lightPosition;
	glm::mat4 projection;
	
	std::list<std::shared_ptr<Box>> boxes;
	Camera cam;
	Shader shader;
	Shader shaderOneColor;
	float alpha = 0;
	bool switchShader = false;
public:
	virtual void Init() override;
	virtual void Draw() override;
	virtual bool Input(std::map<int, bool> keys) override;
	virtual bool MouseInput(int x, int y, bool leftbutton) override;
	virtual void Update(unsigned int delta) override;
	virtual void Close() override;
};

