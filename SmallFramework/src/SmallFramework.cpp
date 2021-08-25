// BasicExampleOpengl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <iostream>
#include "Game.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "GameStateManager.h"
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "Shader.h"

int main()
{
    GameStateManager *gsm = GameStateManager::GetPtr();
    Game game;
    gsm->SetState(&game);
    gsm->GameLoop();
    return 0;
}
