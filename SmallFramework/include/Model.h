#pragma once

#include "Object.h"
#include "Transform.h"
#include "Shader.h"
#include <vector>

class Model : public Object
{
protected:
    std::vector<float> vertex;
    std::vector<unsigned int> index;
    void CreateBuffers();
    Transform transform;
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;    
public:
    virtual void Load() = 0;
    virtual void Draw(Shader *);
    Model();
};
