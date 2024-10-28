#pragma once
#include <functional>
#include <msclr/gcroot.h>
#include <msclr/marshal_cppstd.h>

using namespace System::Collections::Generic;

public ref class GLSWindow
{
public:
    delegate void EventDelegate();
    static int Init(int width, int height, System::String^ name);
    static void Render();
    static void Close();
    static bool ShouldClose();

    static void RegisterOnInit(EventDelegate^ callback);
    static void RegisterOnRendering(EventDelegate^ callback);
    static void RegisterOnClosing(EventDelegate^ callback);
};
