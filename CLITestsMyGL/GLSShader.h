#pragma once
#include "GLShader.h"
#include "SVector2.h"
#include "SVector3.h"
#include "SMatrix.h"

public ref class GLSShader
{
public:
    GLShader* shader;

    GLSShader(System::String^ vertexShaderCode, System::String^ fragmentShaderCode);

    // 析构函数
    ~GLSShader();

    // 激活这个程序对象
    void Use();

    void SetBool(System::String^ name, bool value);
    void SetInt(System::String^ name, int value);
    void SetFloat(System::String^ name, float value);
    void SetVector2(System::String^ name, SVector2^ vector2);
    void SetVector3(System::String^ name, SVector3^ vector3);
    void SetVector4(System::String^ name, float x, float y, float z, float w);
    void SetMatrix(System::String^ name, SMatrix^ value, bool transpose);
};

