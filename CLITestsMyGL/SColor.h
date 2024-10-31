#pragma once
public value struct SColor
{
public:
	float r;
	float g;
	float b;
	float a;

	SColor(float r, float g, float b, float a);
	SColor(int r, int g, int b, int a);
	SColor(float r, float g, float b);
	SColor(int r, int g, int b);

private:
	void Init(float r, float g, float b, float a);
};

