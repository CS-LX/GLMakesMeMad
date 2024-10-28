#pragma once
public ref class GLSWindow
{
public:
    static int Init(int width, int height, System::String^ name);
    static void Render();
    static void Close();
    static bool ShouldClose();
};

