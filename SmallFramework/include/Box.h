#pragma once

#include "Model.h"
#include "Texture.h"

class Box : public Model
{
private:
	float alpha= 0;
	Texture texture;
public:
	Box(Transform& trans);
	void Load() override;
	void Draw(Shader* shader) override;
};

