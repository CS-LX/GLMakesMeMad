#include "GLSShader.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

GLSShader::GLSShader(System::String^ vertexShaderCode, System::String^ fragmentShaderCode) 
{
	shader = new GLShader(marshal_as<std::string>(vertexShaderCode), marshal_as<std::string>(fragmentShaderCode));
}

// 析构函数
GLSShader::~GLSShader()
{
	shader->~GLShader();
	delete shader;
}

// 激活这个程序对象
void GLSShader::Use()
{
	shader->Use();
}

void GLSShader::SetBool(System::String^ name, bool value)
{
	shader->SetBool(marshal_as<std::string>(name), value);
}

void GLSShader::SetInt(System::String^ name, int value)
{
	shader->SetInt(marshal_as<std::string>(name), value);
}

void GLSShader::SetFloat(System::String^ name, float value)
{
	shader->SetFloat(marshal_as<std::string>(name), value);
}

void GLSShader::SetVector2(System::String^ name, SVector2^ vector2)
{
	shader->SetVector2(marshal_as<std::string>(name), *(vector2->vector2));
}

void GLSShader::SetVector3(System::String^ name, SVector3^ vector3)
{
	shader->SetVector3(marshal_as<std::string>(name), *(vector3->vector3));
}

void GLSShader::SetVector4(System::String^ name, float x, float y, float z, float w)
{
	shader->SetVector4(marshal_as<std::string>(name), x, y, z, w);
}

void GLSShader::SetMatrix(System::String^ name, SMatrix^ value, bool transpose)
{
	shader->SetMatrix(marshal_as<std::string>(name), *(value->nativeMatrix), transpose);
}