#include "Texture.h"
#include "stb_image.h"
#include <GL/glew.h>

bool Texture::Load(std::string imagePath)
{
    unsigned char* image = stbi_load(imagePath.c_str(), &widthImage, &heightImage, &channels, 0);
    if (image != nullptr) 
    {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (image != nullptr)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
            glGenerateMipmap(GL_TEXTURE_2D);
            return true;
        }
    }
    return false;
}

unsigned int Texture::GetId()
{
	return id;
}

void Texture::Use()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

