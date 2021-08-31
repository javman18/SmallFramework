#include "Game.h"


void Game::Init() 
{
    model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(4, 4, 4));
    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0, 0, -10));
    auto platform = Platform::GetPtr();
    projection = glm::perspective(glm::radians(45.0f), platform->GetWidth() / (float)platform->GetHeight(), 0.1f, 100.0f);
    plane.Load();
    shader.CreateShader("./assets/Shaders/SimpleVertex.vert", "./assets/Shaders/SimpleVertex.frag");
}

void Game::Draw() 
{
    shader.Use();
    shader.SetUniform("model", model);
    shader.SetUniform("view", view);
    shader.SetUniform("projection", projection);
    model = glm::rotate(model, glm::radians(alpha), glm::vec3(0.0f, 1.0f, 0.0f));

    plane.Draw();
    alpha += 0.1;
}

bool Game::Input(std::map<int, bool> keys) 
{
	return false;
}

bool Game::MouseInput(int x, int y, bool leftbutton) 
{
	return false;
}

void Game::Update(unsigned int delta)
{
}

void Game::Close()
{
}