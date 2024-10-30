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

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(float v);

	//���
	bool Equals(Vector3 other);

	//���������
	bool operator ==(Vector3 v);
	bool operator !=(Vector3 v);
	Vector3 operator +(Vector3 v);
	Vector3 operator -(Vector3 v);
	Vector3 operator *(Vector3 v);
	Vector3 operator *(float d);
	Vector3 operator /(Vector3 v);
	Vector3 operator /(float d);
};
