#pragma once
#include "Vector3.h"
#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
struct DLL_API Matrix
{
public:
	float M11;
	float M21;
	float M31;
	float M41;
	float M12;
	float M22;
	float M32;
	float M42;
	float M13;
	float M23;
	float M33;
	float M43;
	float M14;
	float M24;
	float M34;
	float M44;

	Matrix();
	Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
	//单位矩阵
	static Matrix Identity();
	//0矩阵
	static Matrix Zero();
	//行列式
	float Determinant();
	//从旋转角创建
	static Matrix CreateFromAxisAngle(Vector3 axis, float angle);
	//创建正交矩阵
	static Matrix CreateOrthographic(float width, float height, float nearPlane, float farPlane);
	//通过中心创建正交矩阵
	static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
	//创建透视矩阵
	static Matrix CreatePerspective(float width, float height, float nearPlane, float farPlane);
	//通过视野创建透视矩阵
	static Matrix CreatePerspectiveFieldOfView(float fieldOfViewY, float aspectRatio, float nearPlane, float farPlane);
	//通过中心创建透视矩阵
	static Matrix CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
	//从X轴旋转创建
	static Matrix CreateRotationX(float radians);
	//从Y轴旋转创建
	static Matrix CreateRotationY(float radians);
	//从Z轴旋转创建
	static Matrix CreateRotationZ(float radians);
	//从三轴缩放创建
	static Matrix CreateScale(float scale);
	//从缩放创建
	static Matrix CreateScale(float x, float y, float z);
	//从缩放创建
	static Matrix CreateScale(Vector3 scale);
	//从位移创建
	static Matrix CreateTranslation(float x, float y, float z);
	//从位移创建
	static Matrix CreateTranslation(Vector3 position);

private:
	void Init(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
};

