#include "SColor.h"


SColor::SColor(float r, float g, float b, float a)
{
	Init(r, g, b, a);
}

SColor::SColor(int r, int g, int b, int a)
{
	r = System::Math::Clamp(r, 0, 255);
	g = System::Math::Clamp(g, 0, 255);
	b = System::Math::Clamp(b, 0, 255);
	a = System::Math::Clamp(a, 0, 255);
	Init((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
}

SColor::SColor(float r, float g, float b)
{
	Init(r, g, b, 1.0f);
}

SColor::SColor(int r, int g, int b)
{
	r = System::Math::Clamp(r, 0, 255);
	g = System::Math::Clamp(g, 0, 255);
	b = System::Math::Clamp(b, 0, 255);
	Init((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
}

void SColor::Init(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}