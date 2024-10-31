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

void GLSWindow::RegisterOnMouseMoving(Vector2Delegate^ callback)
{
    msclr::gcroot<Vector2Delegate^> safeCallback = callback;
    auto nativeCallback = [safeCallback](float x, float y) {
        safeCallback->Invoke(x, y);
        };
    GLWindow::RegisterOnMouseMoving(nativeCallback);
}

void GLSWindow::RegisterOnScrollRolling(Vector2Delegate^ callback)
{
    msclr::gcroot<Vector2Delegate^> safeCallback = callback;
    auto nativeCallback = [safeCallback](float x, float y) {
        safeCallback->Invoke(x, y);
        };
    GLWindow::RegisterOnScrollRolling(nativeCallback);
}

int GLSWindow::GetWidth()
{
    return GLWindow::GetWidth();
}

int GLSWindow::GetHeight()
{
    return GLWindow::GetHeight();
}