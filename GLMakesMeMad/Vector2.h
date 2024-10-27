#pragma once
#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
struct DLL_API Vector2
{
public:
	float x;
	float y;

	Vector2(float x, float y);

	Vector2(float v);
};

