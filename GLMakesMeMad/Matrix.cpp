#include "Matrix.h"
#include <corecrt_math.h>

Matrix::Matrix()
{
	Init(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
{
	Init(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}

Matrix Matrix::Identity()
{
	return Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix Matrix::Zero()
{
	return Matrix();
}

float Matrix::Determinant()
{
	float num = (M33 * M44) - (M34 * M43);
	float num2 = (M32 * M44) - (M34 * M42);
	float num3 = (M32 * M43) - (M33 * M42);
	float num4 = (M31 * M44) - (M34 * M41);
	float num5 = (M31 * M43) - (M33 * M41);
	float num6 = (M31 * M42) - (M32 * M41);
	return (M11 * ((M22 * num) - (M23 * num2) + (M24 * num3))) - (M12 * ((M21 * num) - (M23 * num4) + (M24 * num5))) + (M13 * ((M21 * num2) - (M22 * num4) + (M24 * num6))) - (M14 * ((M21 * num3) - (M22 * num5) + (M23 * num6)));
}

Matrix Matrix::CreateFromAxisAngle(Vector3 axis, float angle)
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	float num = sin(angle);
	float num2 = cos(angle);
	float num3 = x * x;
	float num4 = y * y;
	float num5 = z * z;
	float num6 = x * y;
	float num7 = x * z;
	float num8 = y * z;
	Matrix result = Matrix();
	result.M11 = num3 + (num2 * (1.0f - num3));
	result.M12 = num6 - (num2 * num6) + (num * z);
	result.M13 = num7 - (num2 * num7) - (num * y);
	result.M14 = 0.0f;
	result.M21 = num6 - (num2 * num6) - (num * z);
	result.M22 = num4 + (num2 * (1.0f - num4));
	result.M23 = num8 - (num2 * num8) + (num * x);
	result.M24 = 0.0f;
	result.M31 = num7 - (num2 * num7) + (num * y);
	result.M32 = num8 - (num2 * num8) - (num * x);
	result.M33 = num5 + (num2 * (1.0f - num5));
	result.M34 = 0.0f;
	result.M41 = 0.0f;
	result.M42 = 0.0f;
	result.M43 = 0.0f;
	result.M44 = 1.0f;
	return result;
}


Matrix Matrix::CreateOrthographic(float width, float height, float nearPlane, float farPlane)
{
	Matrix result = Matrix();
	result.M11 = 2.0f / width;
	result.M12 = result.M13 = result.M14 = 0.0f;
	result.M22 = 2.0f / height;
	result.M21 = result.M23 = result.M24 = 0.0f;
	result.M33 = 1.0f / (nearPlane - farPlane);
	result.M31 = result.M32 = result.M34 = 0.0f;
	result.M41 = result.M42 = 0.0f;
	result.M43 = nearPlane / (nearPlane - farPlane);
	result.M44 = 1.0f;
	return result;
}

Matrix Matrix::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
	Matrix result = Matrix();
	result.M11 = 2.0f / (right - left);
	result.M12 = 0.0f;
	result.M13 = 0.0f;
	result.M14 = 0.0f;
	result.M21 = 0.0f;
	result.M22 = 2.0f / (top - bottom);
	result.M23 = 0.0f;
	result.M24 = 0.0f;
	result.M31 = 0.0f;
	result.M32 = 0.0f;
	result.M33 = 1.0f / (nearPlane - farPlane);
	result.M34 = 0.0f;
	result.M41 = (left + right) / (left - right);
	result.M42 = (top + bottom) / (bottom - top);
	result.M43 = nearPlane / (nearPlane - farPlane);
	result.M44 = 1.0f;
	return result;
}

Matrix Matrix::CreatePerspective(float width, float height, float nearPlane, float farPlane)
{
	Matrix result = Matrix();
	result.M11 = 2.0f * nearPlane / width;
	result.M12 = result.M13 = result.M14 = 0.0f;
	result.M22 = 2.0f * nearPlane / height;
	result.M21 = result.M23 = result.M24 = 0.0f;
	result.M33 = farPlane / (nearPlane - farPlane);
	result.M31 = result.M32 = 0.0f;
	result.M34 = -1.0f;
	result.M41 = result.M42 = result.M44 = 0.0f;
	result.M43 = nearPlane * farPlane / (nearPlane - farPlane);
	return result;
}

Matrix Matrix::CreatePerspectiveFieldOfView(float fieldOfViewY, float aspectRatio, float nearPlane, float farPlane)
{
	float num = 1.0f / tan(fieldOfViewY * 0.5f);
	Matrix result = Matrix();
	result.M11 = num / aspectRatio;
	result.M12 = result.M13 = result.M14 = 0.0f;
	result.M22 = num;
	result.M21 = result.M23 = result.M24 = 0.0f;
	result.M31 = result.M32 = 0.0f;
	result.M33 = farPlane / (nearPlane - farPlane);
	result.M34 = -1.0f;
	result.M41 = result.M42 = result.M44 = 0.0f;
	result.M43 = nearPlane * farPlane / (nearPlane - farPlane);
	return result;
}

Matrix Matrix::CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
	Matrix result = Matrix();
	result.M11 = 2.0f * nearPlane / (right - left);
	result.M12 = result.M13 = result.M14 = 0.0f;
	result.M22 = 2.0f * nearPlane / (top - bottom);
	result.M21 = result.M23 = result.M24 = 0.0f;
	result.M31 = (left + right) / (right - left);
	result.M32 = (top + bottom) / (top - bottom);
	result.M33 = farPlane / (nearPlane - farPlane);
	result.M34 = -1.0f;
	result.M43 = nearPlane * farPlane / (nearPlane - farPlane);
	result.M41 = result.M42 = result.M44 = 0.0f;
	return result;
}

Matrix Matrix::CreateRotationX(float radians)
{
	Matrix identity = Matrix::Identity();
	float num = cos(radians);
	float num2 = sin(radians);
	identity.M22 = num;
	identity.M23 = num2;
	identity.M32 = 0.0f - num2;
	identity.M33 = num;
	return identity;
}

Matrix Matrix::CreateRotationY(float radians)
{
	Matrix identity = Matrix::Identity();
	float num = cos(radians);
	float num2 = sin(radians);
	identity.M11 = num;
	identity.M13 = 0.0f - num2;
	identity.M31 = num2;
	identity.M33 = num;
	return identity;
}

Matrix Matrix::CreateRotationZ(float radians)
{
	Matrix identity = Matrix::Identity();
	float num = cos(radians);
	float num2 = sin(radians);
	identity.M11 = num;
	identity.M12 = num2;
	identity.M21 = 0.0f - num2;
	identity.M22 = num;
	return identity;
}

Matrix Matrix::CreateScale(float scale)
{
	return Matrix(scale, 0.0f, 0.0f, 0.0f, 0.0f, scale, 0.0f, 0.0f, 0.0f, 0.0f, scale, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix Matrix::CreateScale(float x, float y, float z)
{
	return Matrix(x, 0.0f, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix Matrix::CreateScale(Vector3 scale)
{
	return Matrix(scale.x, 0.0f, 0.0f, 0.0f, 0.0f, scale.y, 0.0f, 0.0f, 0.0f, 0.0f, scale.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix Matrix::CreateTranslation(float x, float y, float z)
{
	return Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, x, y, z, 1.0f);
}

Matrix Matrix::CreateTranslation(Vector3 position)
{
	return Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, position.x, position.y, position.z, 1.0f);
}

void Matrix::Init(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
{
	this->M11 = m11;
	this->M12 = m12;
	this->M13 = m13;
	this->M14 = m14;
	this->M21 = m21;
	this->M22 = m22;
	this->M23 = m23;
	this->M24 = m24;
	this->M31 = m31;
	this->M32 = m32;
	this->M33 = m33;
	this->M34 = m34;
	this->M41 = m41;
	this->M42 = m42;
	this->M43 = m43;
	this->M44 = m44;
}