#include "GLSWindow.h"
#include "GLWindow.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <functional>
#include <msclr/gcroot.h>

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

void GLSWindow::RegisterOnInit(EventDelegate^ callback)
{
    msclr::gcroot<EventDelegate^> safeCallback = callback;
    auto nativeCallback = [safeCallback]() {
        safeCallback->Invoke();
        };
    GLWindow::RegisterOnInit(nativeCallback);
}

void GLSWindow::RegisterOnRendering(EventDelegate^ callback)
{
    msclr::gcroot<EventDelegate^> safeCallback = callback;
    auto nativeCallback = [safeCallback]() {
        safeCallback->Invoke();
        };
    GLWindow::RegisterOnRendering(nativeCallback);
}

void GLSWindow::RegisterOnClosing(EventDelegate^ callback)
{
    msclr::gcroot<EventDelegate^> safeCallback = callback;
    auto nativeCallback = [safeCallback]() {
        safeCallback->Invoke();
        };
    GLWindow::RegisterOnClosing(nativeCallback);
}