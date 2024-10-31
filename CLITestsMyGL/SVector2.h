#pragma once
#include "Vector2.h"
public value struct SVector2
{
public:
	float x;
	float y;

	SVector2(float x, float y);
	SVector2(float v);

	//���
	bool Equals(SVector2 other);

	// ��̬���������
	static SVector2 operator +(SVector2 a, SVector2 b);
	static SVector2 operator -(SVector2 a, SVector2 b);
	static SVector2 operator *(SVector2 a, SVector2 b);
	static bool operator ==(SVector2 a, SVector2 b);
	static bool operator !=(SVector2 a, SVector2 b);

	// GetHashCode ��д
	virtual int GetHashCode() override;
};