#version 330 core
out vec4 FragColor;
in vec3 colorS;
in vec2 uvS;
uniform vec3 color;
uniform sampler2D texImage;
void main()
{
   FragColor = vec4(0, 0, 1, 1);
}