#include "Plane.h"

Plane::Plane()
{
    vertex = {
     0.5f, 0.5f,0.0f,0.0,0.0,1.0,1.0f, 1.0f,
     0.5f,-0.5f,0.0f,1.0,0.0,0.0,1.0f, 0.0f,
    -0.5f,-0.5f,0.0f,0.0,1.0,0.0,0.0f, 0.0f,
    -0.5f, 0.5f,0.0f,1.0,0.0,1.0,0.0f, 1.0f,
    };

    index = {
        1,2,3,
        0,1,3
    };
}

void Plane::Load() 
{
    CreateBuffers();
}