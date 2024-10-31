#pragma once
#include <string>
#include <functional>

#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


class DLL_API GLWindow
{
public:
    using EventCallback = std::function<void()>;

    static int Init(int width, int height, const std::string& windowName);
    static void Render();
    static void Close();
    static bool ShouldClose();
    static int GetWidth();
    static int GetHeight();


    // 事件注册方法
    static void RegisterOnInit(EventCallback callback);
    static void RegisterOnRendering(EventCallback callback);
    static void RegisterOnClosing(EventCallback callback);
    static void RegisterOnMouseMoving(std::function<void(float, float)> callback);
    static void RegisterOnScrollRolling(std::function<void(float, float)> callback);

private:
    //static void FramebufferSizeCallback(int width, int height);
};