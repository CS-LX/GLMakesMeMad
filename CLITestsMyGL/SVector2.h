#pragma once
#include "Vector2.h"
public ref struct SVector2
{
public:
	Vector2* vector2;

	property float X
	{
		float get() { return vector2->x; }
		void set(float value) { vector2->x = value; }
	}

	property float Y
	{
		float get() { return vector2->y; }
		void set(float value) { vector2->y = value; }
	}

	SVector2();
	SVector2(float x, float y);
	SVector2(float v);
	~SVector2();

	//���
	bool Equals(SVector2 other);

	// ��̬���������
	static SVector2^ operator +(SVector2^ a, SVector2^ b);
	static SVector2^ operator -(SVector2^ a, SVector2^ b);
	static SVector2^ operator *(SVector2^ a, SVector2^ b);
	static bool operator ==(SVector2^ a, SVector2^ b);
	static bool operator !=(SVector2^ a, SVector2^ b);

	// GetHashCode ��д
	virtual int GetHashCode() override;

private:
	SVector2(const SVector2% other);
	SVector2(const Vector2& vec);
};