#pragma once
#include "Vector2.h"
public value struct SVector2
{
public:
	float x;
	float y;

	SVector2(float x, float y);
	SVector2(float v);

	//相等
	bool Equals(SVector2 other);

	// 静态运算符重载
	static SVector2 operator +(SVector2 a, SVector2 b);
	static SVector2 operator -(SVector2 a, SVector2 b);
	static SVector2 operator *(SVector2 a, SVector2 b);
	static bool operator ==(SVector2 a, SVector2 b);
	static bool operator !=(SVector2 a, SVector2 b);

	// GetHashCode 重写
	virtual int GetHashCode() override;
};