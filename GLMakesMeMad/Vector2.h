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

	Vector2();
	Vector2(float x, float y);
	Vector2(float v);

	//���
	bool Equals(Vector2 other);

	//���������
	bool operator ==(Vector2 v);
	bool operator !=(Vector2 v);
	Vector2 operator +(Vector2 v);
	Vector2 operator -(Vector2 v);
	Vector2 operator *(Vector2 v);
	Vector2 operator *(float d);
	Vector2 operator /(Vector2 v);
	Vector2 operator /(float d);
};

