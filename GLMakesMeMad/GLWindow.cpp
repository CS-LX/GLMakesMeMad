#include "GLWindow.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

GLFWwindow* window;
std::vector<GLWindow::EventCallback> onInitCallbacks;
std::vector<GLWindow::EventCallback> renderingCallbacks;
std::vector<GLWindow::EventCallback> closingCallbacks;

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int GLWindow::Init(int width, int height, const std::string& windowName)
{
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, width, height);

    // 设置帧缓冲大小回调
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    for (auto& callback : onInitCallbacks) {
        callback();
    }

    return 0;
}

void GLWindow::Render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除深度缓冲

    for (auto& callback : renderingCallbacks) {
        callback();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GLWindow::Close()
{
    for (auto& callback : closingCallbacks) {
        callback();
    }

    glfwDestroyWindow(window); // 销毁窗口
    glfwTerminate();           // 终止GLFW
}

bool GLWindow::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void GLWindow::RegisterOnInit(EventCallback callback)
{
    onInitCallbacks.push_back(callback);
}

void GLWindow::RegisterOnRendering(EventCallback callback)
{
    renderingCallbacks.push_back(callback);
}

void GLWindow::RegisterOnClosing(EventCallback callback)
{
    closingCallbacks.push_back(callback);
}