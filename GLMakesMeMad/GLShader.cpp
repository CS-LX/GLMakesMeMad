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
    // ���ļ�
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�: " << filePath << std::endl;
        return nullptr;
    }

    // ��ȡ�ļ���С
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Ϊ�ļ����ݷ����ڴ� (���� \0 ������)
    char* buffer = new char[fileSize + 1];

    // ��ȡ�ļ����ݵ�������
    if (!file.read(buffer, fileSize))
    {
        std::cerr << "�ļ���ȡʧ��: " << filePath << std::endl;
        delete[] buffer; // �ͷ��ڴ�
        return nullptr;
    }

    // ����ַ���������
    buffer[fileSize] = '\0';

    return buffer; // �����ļ����ݵ�ָ��
}

GLShader::GLShader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
    GLShader::Init(vertexShaderCode, fragmentShaderCode);
}

GLShader::GLShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
{
    GLShader::Init(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
}

GLShader* GLShader::Load(const std::string& vshPath, const std::string& pshPath)
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
    vertexShader = new GLVertexShader(vertexShaderCode);  // ��̬�����ڴ�
    fragmentShader = new GLFragmentShader(fragmentShaderCode);

    // ���Ӳ�������ɫ��
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

    // ������֮������ɾ����ɫ������
    glDeleteShader(vertexShader->id);
    glDeleteShader(fragmentShader->id);
}

// ��������
GLShader::~GLShader()
{
    // �ͷŶ�̬�������ɫ������
    delete vertexShader;
    delete fragmentShader;
}

// ��������������
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
void GLShader::SetVector2(const std::string& name, Vector2 vector2) const
{
    glUniform2f(GetUniformLocation(name), vector2.x, vector2.y);
}
void GLShader::SetVector2(const std::string& name, float x, float y) const
{
    glUniform2f(GetUniformLocation(name), x, y);
}
void GLShader::SetVector3(const std::string& name, Vector3 vector3) const
{
    glUniform3f(GetUniformLocation(name), vector3.x, vector3.y, vector3.z);
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
void GLShader::SetMatrix(const std::string& name, Matrix matrix, bool transpose)
{
    float values[16] = {
        matrix.M11, matrix.M12, matrix.M13, matrix.M14,
        matrix.M21, matrix.M22, matrix.M23, matrix.M24,
        matrix.M31, matrix.M32, matrix.M33, matrix.M34,
        matrix.M41, matrix.M42, matrix.M43, matrix.M44
    };
    glUniformMatrix4fv(GetUniformLocation(name), 1, transpose ? GL_TRUE : GL_FALSE, values);
}
void GLShader::SetMatrix(const std::string& name, float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44, bool transpose)
{
    float values[16] = {
        m11, m12, m13, m14,
        m21, m22, m23, m24,
        m31, m32, m33, m34,
        m41, m42, m43, m44
    };
    glUniformMatrix4fv(GetUniformLocation(name), 1, transpose ? GL_TRUE : GL_FALSE, values);
}