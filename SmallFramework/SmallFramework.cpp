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


const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 vertexPos;\n"
                                 "layout (location = 1) in vec3 color;\n"
                                 "layout (location = 2) in vec2 uv;\n"
                                 "out vec3 colorS;\n"
                                 "out vec2 uvS;\n"
                                 "uniform mat4 model;\n"
                                 "uniform mat4 projection;\n"
                                 "uniform mat4 view;\n"
                                 "void main()\n"
                                 "{\n"
                                 "    gl_Position = projection *view*  model*vec4(vertexPos, 1);\n"
                                 "    colorS = color;\n"
                                 "    uvS = uv;\n" 
                                 "}\n\0";


const char* fragmentShaderSource = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "in vec3 colorS;\n"
                                    "in vec2 uvS;\n"
                                    "uniform vec3 color;\n"
                                    "uniform sampler2D texImage;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = texture(texImage,uvS);\n"
                                    "}\n\0";

const int width = 640;
const int height = 480;
int main()
{
    GameStateManager *gsm = GameStateManager::GetPtr();
    Game game;
    gsm->SetState(&game);
    gsm->GameLoop();

    /*int widthImage;
    int heightImage;
    int channels;
    unsigned char* image = stbi_load("tex.png", &widthImage, &heightImage, &channels, 0);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(width, height, "example opengl", NULL, NULL);

    glfwMakeContextCurrent(window);

    glewInit();

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (image != nullptr)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    

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


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

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
        
        glBindTexture(GL_TEXTURE_2D, texture);

        glUseProgram(shaderProgram);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
