#pragma once
#include "GLShader.h"
public ref class GLSShader
{
public:
    GLShader* shader;

    GLSShader(System::String^ vertexShaderCode, System::String^ fragmentShaderCode);

    // 析构函数
    ~GLSShader();

    // 激活这个程序对象
    void Use();
};

