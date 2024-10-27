#include "Color.h"
#include "MathF.h"

Color::Color()
{
	Init(0.0f, 0.0f, 0.0f, 0.0f);
}

Color::Color(float r, float g, float b, float a)
{
	Init(r, g, b, a);
}

Color::Color(int r, int g, int b, int a)
{
	r = MathF::Clamp(r, 0, 255);
	g = MathF::Clamp(g, 0, 255);
	b = MathF::Clamp(b, 0, 255);
	a = MathF::Clamp(a, 0, 255);
	Init((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
}

Color::Color(float r, float g, float b)
{
	Init(r, g, b, 1.0f);
}

Color::Color(int r, int g, int b)
{
	r = MathF::Clamp(r, 0, 255);
	g = MathF::Clamp(g, 0, 255);
	b = MathF::Clamp(b, 0, 255);
	Init((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
}

void Color::Init(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}