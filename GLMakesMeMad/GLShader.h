#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include "GLVertexShader.h";
#include "GLFragmentShader.h"
#include <string>

#pragma once
class DLL_API GLShader
{
public:
    unsigned int id;
    GLVertexShader* vertexShader;
    GLFragmentShader* fragmentShader;

    GLShader(const char* vertexShaderCode, const char* fragmentShaderCode);
    GLShader(std::string& vertexShaderCode, std::string& fragmentShaderCode);
    static GLShader* Load(std::string& vshPath, std::string& pshPath);

    // 析构函数
    ~GLShader();

    // 激活这个程序对象
    void Use();

    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVector2(const std::string& name, float x, float y) const;
    void SetVector3(const std::string& name, float x, float y, float z) const;
    void SetVector4(const std::string& name, float x, float y, float z, float w) const;
    void SetMatrix(const std::string& name, float* value);

private:
    int GetUniformLocation(const std::string& name) const;

    void Init(const char* vertexShaderCode, const char* fragmentShaderCode);
};

