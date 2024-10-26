#pragma once
#include "GLShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "GLFragmentShader.h"
#include "GLVertexShader.h"

static const char* ReadFile(const std::string& filePath) {
    // 打开文件
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return nullptr;
    }

    // 获取文件大小
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // 为文件内容分配内存 (包括 \0 结束符)
    char* buffer = new char[fileSize + 1];

    // 读取文件内容到缓冲区
    if (!file.read(buffer, fileSize))
    {
        std::cerr << "文件读取失败: " << filePath << std::endl;
        delete[] buffer; // 释放内存
        return nullptr;
    }

    // 添加字符串结束符
    buffer[fileSize] = '\0';

    return buffer; // 返回文件内容的指针
}

GLShader::GLShader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
    GLShader::Init(vertexShaderCode, fragmentShaderCode);
}

GLShader::GLShader(std::string& vertexShaderCode, std::string& fragmentShaderCode)
{
    GLShader::Init(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
}

GLShader* GLShader::Load(std::string& vshPath, std::string& pshPath)
{
    const char* vsh = ReadFile(vshPath);
    const char* psh = ReadFile(pshPath);
    if (!vsh || !psh)
    {
        return nullptr;
    }
    return new GLShader(vsh, psh);
}


void GLShader::Init(const char* vertexShaderCode, const char* fragmentShaderCode)
{
    id = glCreateProgram();
    vertexShader = new GLVertexShader(vertexShaderCode);  // 动态分配内存
    fragmentShader = new GLFragmentShader(fragmentShaderCode);

    // 附加并链接着色器
    glAttachShader(id, vertexShader->id);
    glAttachShader(id, fragmentShader->id);
    glLinkProgram(id);

    int success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "Failed to create or link Shader Program\n" << infoLog << std::endl;
    }

    // 在链接之后立即删除着色器对象
    glDeleteShader(vertexShader->id);
    glDeleteShader(fragmentShader->id);
}

// 析构函数
GLShader::~GLShader()
{
    // 释放动态分配的着色器对象
    delete vertexShader;
    delete fragmentShader;
}

// 激活这个程序对象
void GLShader::Use()
{
    glUseProgram(id);
}

int GLShader::GetUniformLocation(const std::string& name) const
{
    int location = glGetUniformLocation(id, name.c_str());
    //if (location < 0) std::cout << "Coundn't find uniform \"" << name << "\" in shader." << std::endl;
    return location;
}

void GLShader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(GetUniformLocation(name), (int)value);
}
void GLShader::SetInt(const std::string& name, int value) const
{
    glUniform1i(GetUniformLocation(name), value);
}
void GLShader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(GetUniformLocation(name), value);
}
void GLShader::SetVector2(const std::string& name, float x, float y) const
{
    glUniform2f(GetUniformLocation(name), x, y);
}
void GLShader::SetVector3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(GetUniformLocation(name), x, y, z);
}
void GLShader::SetVector4(const std::string& name, float x, float y, float z, float w) const
{
    glUniform4f(GetUniformLocation(name), x, y, z, w);
}
void GLShader::SetMatrix(const std::string& name, float* value)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value);
}
