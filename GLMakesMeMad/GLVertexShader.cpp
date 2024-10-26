#pragma once
#include "GLVertexShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLVertexShader::GLVertexShader(const char* code)
{
	id = glCreateShader(GL_VERTEX_SHADER);//������ɫ��
	//��һ�����ǰ������ɫ��Դ�븽�ӵ���ɫ�������ϣ�Ȼ�������
	glShaderSource(id, 1, &code, NULL);
	glCompileShader(id);

	//����Ƿ����ɹ�
	int  success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "Failed to compile Vertex Shader\n" << infoLog << std::endl;
	}
}