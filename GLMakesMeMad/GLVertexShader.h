#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#pragma once
class DLL_API GLVertexShader
{
public:
	unsigned int id;
	GLVertexShader(const char* code);
};

