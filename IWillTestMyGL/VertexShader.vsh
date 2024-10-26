#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aTexCoord;

//顶点信息
out vec2 TexCoord;
out vec3 VerColor;
out vec3 VerNormal;


void main()
{
    gl_Position = vec4(aPos, 1.0);
    VerColor = aColor;
    TexCoord = aTexCoord;
    VerNormal = aNormal;
}