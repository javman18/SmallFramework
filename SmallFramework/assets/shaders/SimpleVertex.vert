#version 330 core
layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;
out vec3 colorS;
out vec2 uvS;
void main()
{
    gl_Position = vec4(vertexPos, 1);
    colorS = color;
    uvS = uv;
}