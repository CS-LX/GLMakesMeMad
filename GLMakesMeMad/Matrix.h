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
	//��λ����
	static Matrix Identity();
	//0����
	static Matrix Zero();
	//����ʽ
	float Determinant();
	//����ת�Ǵ���
	static Matrix CreateFromAxisAngle(Vector3 axis, float angle);
	//������������
	static Matrix CreateOrthographic(float width, float height, float nearPlane, float farPlane);
	//ͨ�����Ĵ�����������
	static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
	//����͸�Ӿ���
	static Matrix CreatePerspective(float width, float height, float nearPlane, float farPlane);
	//ͨ����Ұ����͸�Ӿ���
	static Matrix CreatePerspectiveFieldOfView(float fieldOfViewY, float aspectRatio, float nearPlane, float farPlane);
	//ͨ�����Ĵ���͸�Ӿ���
	static Matrix CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
	//��X����ת����
	static Matrix CreateRotationX(float radians);
	//��Y����ת����
	static Matrix CreateRotationY(float radians);
	//��Z����ת����
	static Matrix CreateRotationZ(float radians);
	//���������Ŵ���
	static Matrix CreateScale(float scale);
	//�����Ŵ���
	static Matrix CreateScale(float x, float y, float z);
	//�����Ŵ���
	static Matrix CreateScale(Vector3 scale);
	//��λ�ƴ���
	static Matrix CreateTranslation(float x, float y, float z);
	//��λ�ƴ���
	static Matrix CreateTranslation(Vector3 position);

private:
	void Init(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
};

