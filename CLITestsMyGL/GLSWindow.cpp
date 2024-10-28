#include "GLSWindow.h"
#include "GLWindow.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

int GLSWindow::Init(int width, int height, System::String^ name)
{
	return GLWindow::Init(width, height, marshal_as<std::string>(name));
}

void GLSWindow::Render()
{
	GLWindow::Render();
}

void GLSWindow::Close()
{
	GLWindow::Close();
}

bool GLSWindow::ShouldClose()
{
	return GLWindow::ShouldClose();
}