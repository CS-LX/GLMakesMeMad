#pragma once
#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
struct DLL_API Color
{
public:
	float r;
	float g;
	float b;
	float a;

	Color(float r, float g, float b, float a);
	Color(int r, int g, int b, int a);
	Color(float r, float g, float b);
	Color(int r, int g, int b);

private:
	void Init(float r, float g, float b, float a);
};

