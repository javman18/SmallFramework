#pragma once
#include <string>
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

