#pragma once
#include "GLShader.h"
public ref class GLSShader
{
public:
    GLShader* shader;

    GLSShader(System::String^ vertexShaderCode, System::String^ fragmentShaderCode);

    // ��������
    ~GLSShader();

    // ��������������
    void Use();
};

