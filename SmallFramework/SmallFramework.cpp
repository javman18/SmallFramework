// BasicExampleOpengl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <iostream>
#include "Game.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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


    /*



    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(4,4,4));
    glm::mat4 view(1); 
    view = glm::translate(view, glm::vec3(0, 0, -10));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), width / (float)height, 0.1f, 100.0f);
    glm::vec3 color(1.0f, 0.0f, 0.0f);
    float alpha = 0;
    while (!glfwWindowShouldClose(window))
    {
        model = glm::rotate(model, glm::radians(alpha), glm::vec3(0.0f, 1.0f, 0.0f));
       // view = glm::translate(view, glm::vec3(0, 0, alpha));
      
        color.x = (rand() % 100) / 100.0f;
        color.y = (rand() % 100) / 100.0f;
        color.z = (rand() % 100) / 100.0f;
        unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
        unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
        unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
        unsigned int colorLoc = glGetUniformLocation(shaderProgram, "color");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniform3f(colorLoc, color.x, color.y, color.z);
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        

        alpha -= 0.001;
    }
    */
}