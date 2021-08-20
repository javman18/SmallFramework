#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Object.h"

class Texture : public Object
{
private:
    std::string imagePath;
    int widthImage;
    int heightImage;
    int channels;
    unsigned int id;
public:
    bool Load(std::string imagePath);
    unsigned int GetId();
    void Use();
};

