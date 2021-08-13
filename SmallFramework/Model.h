#pragma once

#include "Object.h"
#include <vector>

class Model : public Object
{
protected:
    std::vector<float> vertex;
    std::vector<float> index;
    void CreateBuffers();
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;    
public:
    virtual void Load() = 0;
    void Draw();
    Model();
};
