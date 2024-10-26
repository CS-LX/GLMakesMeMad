#include "GLFragmentShader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFragmentShader::GLFragmentShader(const char* code)
{
	id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(id, 1, &code, NULL);
	glCompileShader(id);

	int  success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "Failed to compile Fragment Shader\n" << infoLog << std::endl;
	}
}