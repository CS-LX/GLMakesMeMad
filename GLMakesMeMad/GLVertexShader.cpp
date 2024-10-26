#pragma once
#include "GLVertexShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLVertexShader::GLVertexShader(const char* code)
{
	id = glCreateShader(GL_VERTEX_SHADER);//创建着色器
	//下一步我们把这个着色器源码附加到着色器对象上，然后编译它
	glShaderSource(id, 1, &code, NULL);
	glCompileShader(id);

	//检查是否编译成功
	int  success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "Failed to compile Vertex Shader\n" << infoLog << std::endl;
	}
}