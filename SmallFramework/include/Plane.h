#pragma once

#include "Model.h"
#include "Texture.h"

class Plane : public Model
{
private:
	Texture texture;
public:
	Plane();
	void Load() override;
	void Draw() override;
};

