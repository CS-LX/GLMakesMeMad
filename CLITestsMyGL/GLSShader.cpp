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