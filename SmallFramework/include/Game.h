#pragma once
#include "GameState.h"
#include "Plane.h"
#include "Shader.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Game : public GameState
{
private:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	Plane plane;
	Shader shader;
	float alpha = 0;
public:
	virtual void Init() override;
	virtual void Draw() override;
	virtual bool Input(std::map<int, bool> keys) override;
	virtual bool MouseInput(int x, int y, bool leftbutton) override;
	virtual void Update(unsigned int delta) override;
	virtual void Close() override;
};

