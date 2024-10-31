#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include "GLVertexShader.h"
#include "GLFragmentShader.h"
#include "Vector3.h"
#include "Vector2.h"
#include <string>
#include "Matrix.h"

#pragma once
class DLL_API GLShader
{
public:
    unsigned int id;
    GLVertexShader* vertexShader;
    GLFragmentShader* fragmentShader;

    GLShader(const char* vertexShaderCode, const char* fragmentShaderCode);
    GLShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
    static GLShader* Load(const std::string& vshPath, const std::string& pshPath);

    // 析构函数
    ~GLShader();

    // 激活这个程序对象
    void Use();

    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVector2(const std::string& name, Vector2 vector2) const;
    void SetVector2(const std::string& name, float x, float y) const;
    void SetVector3(const std::string& name, Vector3 vector3) const;
    void SetVector3(const std::string& name, float x, float y, float z) const;
    void SetVector4(const std::string& name, float x, float y, float z, float w) const;
    void SetMatrix(const std::string& name, float* value);
    void SetMatrix(const std::string& name, Matrix value, bool transpose = false);
    void SetMatrix(const std::string& name, float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44, bool transpose = false);

private:
    int GetUniformLocation(const std::string& name) const;

    void Init(const char* vertexShaderCode, const char* fragmentShaderCode);
};

