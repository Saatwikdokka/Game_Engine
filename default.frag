#version 330 core

in vec3 color;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D tex0;

void main()
{
    FragColor = texture(tex0, texCoord) * vec4(color, 1.0);
}
