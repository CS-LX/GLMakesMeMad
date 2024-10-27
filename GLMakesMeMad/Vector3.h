#pragma once
#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
struct DLL_API Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3(float x, float y, float z);

	Vector3(float v);
};
