#version 330 core
out vec4 FragColor;
in vec3 colorS;
in vec2 uvS;
uniform vec3 color;
uniform sampler2D texImage;
void main()
{
   FragColor = texture(texImage,uvS);
}