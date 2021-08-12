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

    float vertex[] = {
         0.5f, 0.5f,0.0f,0.0,0.0,1.0,1.0f, 1.0f,
         0.5f,-0.5f,0.0f,1.0,0.0,0.0,1.0f, 0.0f,
        -0.5f,-0.5f,0.0f,0.0,1.0,0.0,0.0f, 0.0f,
        -0.5f, 0.5f,0.0f,1.0,0.0,1.0,0.0f, 1.0f,
    };
    
    unsigned int index[] = {
        1,2,3,
        0,1,3
    };
    //mover a la memoria los vertices
    unsigned int VAO=0;
    unsigned int VBO=0;
    unsigned int EBO = 0;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

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
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
       

        glBindVertexArray(VAO);
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
        

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
        alpha -= 0.001;
    }
    */
}