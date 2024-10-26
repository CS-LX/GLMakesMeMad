#pragma once
#include <string>

#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


class DLL_API GLWindow
{
public:
    static int Init(int width, int height, const std::string& windowName);
    static void Render();
    static void Close();

private:
    //static void FramebufferSizeCallback(int width, int height);
};