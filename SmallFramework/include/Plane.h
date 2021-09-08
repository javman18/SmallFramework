#pragma once

#include "Model.h"
#include "Texture.h"
#include "Shader.h"

class Plane : public Model
{
private:
	Texture texture;
public:
	Plane();
	void Load() override;
	void Draw(Shader *) override;
};

