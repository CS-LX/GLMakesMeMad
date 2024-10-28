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

// ��������
GLSShader::~GLSShader()
{
	shader->~GLShader();
	delete shader;
}

// ��������������
void GLSShader::Use()
{
	shader->Use();
}