#include "Game.h"

//paso 1 dibujar una caja
//paso 2 exponer las luces del shader ADSL hacia c++
//paso 3 color una caja que represente a la luz

void Game::Init() 
{
    model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(4, 4, 4));
    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0, 0, -20));
    view = glm::rotate(view, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    auto platform = Platform::GetPtr();
    projection = glm::perspective(glm::radians(45.0f), platform->GetWidth() / (float)platform->GetHeight(), 0.1f, 400.0f);

    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            for (int z = 0; z < 10; ++z)
            {
                Transform boxTransform(glm::vec3(x*3, y*3, z*-3), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0));
                auto box = std::shared_ptr<Box>(new Box(boxTransform));
                box->Load();
                boxes.push_back(box);
            }
        }
    }
    
    shader.CreateShader("./assets/Shaders/ADSL.vert", "./assets/Shaders/ADSL.frag");
    shaderOneColor.CreateShader("./assets/Shaders/OneColor.vert", "./assets/Shaders/OneColor.frag");
    lightPosition.x = 0;
    lightPosition.y = 0;
    lightPosition.z = 0;
}

void Game::Draw() 
{


    lightPosition.x = alpha;
    lightPosition.z = alpha;
   // plane.Draw();    
    model = glm::rotate(model, glm::radians(alpha), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto box : boxes)
    {
        if (switchShader)
        {
            shader.Use();
            shader.SetUniform("model", model);
            shader.SetUniform("lightPosition", lightPosition);
            shader.SetUniform("view", view);
            shader.SetUniform("projection", projection);  
            box->Draw(&shader);
        }
        else
        {
            shaderOneColor.Use();
            shaderOneColor.SetUniform("model", model);
            shaderOneColor.SetUniform("lightPosition", lightPosition);
            shaderOneColor.SetUniform("view", view);
            shaderOneColor.SetUniform("projection", projection);
            box->Draw(&shaderOneColor);
        }
                
        switchShader = !switchShader;
    }
   
    //alpha += 0.01;
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