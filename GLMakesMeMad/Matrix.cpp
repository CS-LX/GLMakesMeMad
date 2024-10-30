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

Matrix Matrix::Transpose(Matrix m)
{
	return Matrix(m.M11, m.M21, m.M31, m.M41, m.M12, m.M22, m.M32, m.M42, m.M13, m.M23, m.M33, m.M43, m.M14, m.M24, m.M34, m.M44);
}

Matrix Matrix::Invert(Matrix m)
{
	float m2 = m.M11;
	float m3 = m.M12;
	float m4 = m.M13;
	float m5 = m.M14;
	float m6 = m.M21;
	float m7 = m.M22;
	float m8 = m.M23;
	float m9 = m.M24;
	float m10 = m.M31;
	float m11 = m.M32;
	float m12 = m.M33;
	float m13 = m.M34;
	float m14 = m.M41;
	float m15 = m.M42;
	float m16 = m.M43;
	float m17 = m.M44;
	float num = (m12 * m17) - (m13 * m16);
	float num2 = (m11 * m17) - (m13 * m15);
	float num3 = (m11 * m16) - (m12 * m15);
	float num4 = (m10 * m17) - (m13 * m14);
	float num5 = (m10 * m16) - (m12 * m14);
	float num6 = (m10 * m15) - (m11 * m14);
	float num7 = (m7 * num) - (m8 * num2) + (m9 * num3);
	float num8 = 0.0f - ((m6 * num) - (m8 * num4) + (m9 * num5));
	float num9 = (m6 * num2) - (m7 * num4) + (m9 * num6);
	float num10 = 0.0f - ((m6 * num3) - (m7 * num5) + (m8 * num6));
	float num11 = 1.0f / ((m2 * num7) + (m3 * num8) + (m4 * num9) + (m5 * num10));
	Matrix result = Matrix();
	result.M11 = num7 * num11;
	result.M21 = num8 * num11;
	result.M31 = num9 * num11;
	result.M41 = num10 * num11;
	result.M12 = (0.0f - ((m3 * num) - (m4 * num2) + (m5 * num3))) * num11;
	result.M22 = ((m2 * num) - (m4 * num4) + (m5 * num5)) * num11;
	result.M32 = (0.0f - ((m2 * num2) - (m3 * num4) + (m5 * num6))) * num11;
	result.M42 = ((m2 * num3) - (m3 * num5) + (m4 * num6)) * num11;
	float num12 = (m8 * m17) - (m9 * m16);
	float num13 = (m7 * m17) - (m9 * m15);
	float num14 = (m7 * m16) - (m8 * m15);
	float num15 = (m6 * m17) - (m9 * m14);
	float num16 = (m6 * m16) - (m8 * m14);
	float num17 = (m6 * m15) - (m7 * m14);
	result.M13 = ((m3 * num12) - (m4 * num13) + (m5 * num14)) * num11;
	result.M23 = (0.0f - ((m2 * num12) - (m4 * num15) + (m5 * num16))) * num11;
	result.M33 = ((m2 * num13) - (m3 * num15) + (m5 * num17)) * num11;
	result.M43 = (0.0f - ((m2 * num14) - (m3 * num16) + (m4 * num17))) * num11;
	float num18 = (m8 * m13) - (m9 * m12);
	float num19 = (m7 * m13) - (m9 * m11);
	float num20 = (m7 * m12) - (m8 * m11);
	float num21 = (m6 * m13) - (m9 * m10);
	float num22 = (m6 * m12) - (m8 * m10);
	float num23 = (m6 * m11) - (m7 * m10);
	result.M14 = (0.0f - ((m3 * num18) - (m4 * num19) + (m5 * num20))) * num11;
	result.M24 = ((m2 * num18) - (m4 * num21) + (m5 * num22)) * num11;
	result.M34 = (0.0f - ((m2 * num19) - (m3 * num21) + (m5 * num23))) * num11;
	result.M44 = ((m2 * num20) - (m3 * num22) + (m4 * num23)) * num11;
	return result;
}

Matrix Matrix::Lerp(Matrix m1, Matrix m2, float f)
{
	m1.M11 += (m2.M11 - m1.M11) * f;
	m1.M12 += (m2.M12 - m1.M12) * f;
	m1.M13 += (m2.M13 - m1.M13) * f;
	m1.M14 += (m2.M14 - m1.M14) * f;
	m1.M21 += (m2.M21 - m1.M21) * f;
	m1.M22 += (m2.M22 - m1.M22) * f;
	m1.M23 += (m2.M23 - m1.M23) * f;
	m1.M24 += (m2.M24 - m1.M24) * f;
	m1.M31 += (m2.M31 - m1.M31) * f;
	m1.M32 += (m2.M32 - m1.M32) * f;
	m1.M33 += (m2.M33 - m1.M33) * f;
	m1.M34 += (m2.M34 - m1.M34) * f;
	m1.M41 += (m2.M41 - m1.M41) * f;
	m1.M42 += (m2.M42 - m1.M42) * f;
	m1.M43 += (m2.M43 - m1.M43) * f;
	m1.M44 += (m2.M44 - m1.M44) * f;
	return m1;
}

Matrix Matrix::MultiplyRestricted(Matrix* m1, Matrix* m2)
{
	Matrix result = Matrix();
	result.M11 = (m1->M11 * m2->M11) + (m1->M12 * m2->M21) + (m1->M13 * m2->M31) + (m1->M14 * m2->M41);
	result.M12 = (m1->M11 * m2->M12) + (m1->M12 * m2->M22) + (m1->M13 * m2->M32) + (m1->M14 * m2->M42);
	result.M13 = (m1->M11 * m2->M13) + (m1->M12 * m2->M23) + (m1->M13 * m2->M33) + (m1->M14 * m2->M43);
	result.M14 = (m1->M11 * m2->M14) + (m1->M12 * m2->M24) + (m1->M13 * m2->M34) + (m1->M14 * m2->M44);
	result.M21 = (m1->M21 * m2->M11) + (m1->M22 * m2->M21) + (m1->M23 * m2->M31) + (m1->M24 * m2->M41);
	result.M22 = (m1->M21 * m2->M12) + (m1->M22 * m2->M22) + (m1->M23 * m2->M32) + (m1->M24 * m2->M42);
	result.M23 = (m1->M21 * m2->M13) + (m1->M22 * m2->M23) + (m1->M23 * m2->M33) + (m1->M24 * m2->M43);
	result.M24 = (m1->M21 * m2->M14) + (m1->M22 * m2->M24) + (m1->M23 * m2->M34) + (m1->M24 * m2->M44);
	result.M31 = (m1->M31 * m2->M11) + (m1->M32 * m2->M21) + (m1->M33 * m2->M31) + (m1->M34 * m2->M41);
	result.M32 = (m1->M31 * m2->M12) + (m1->M32 * m2->M22) + (m1->M33 * m2->M32) + (m1->M34 * m2->M42);
	result.M33 = (m1->M31 * m2->M13) + (m1->M32 * m2->M23) + (m1->M33 * m2->M33) + (m1->M34 * m2->M43);
	result.M34 = (m1->M31 * m2->M14) + (m1->M32 * m2->M24) + (m1->M33 * m2->M34) + (m1->M34 * m2->M44);
	result.M41 = (m1->M41 * m2->M11) + (m1->M42 * m2->M21) + (m1->M43 * m2->M31) + (m1->M44 * m2->M41);
	result.M42 = (m1->M41 * m2->M12) + (m1->M42 * m2->M22) + (m1->M43 * m2->M32) + (m1->M44 * m2->M42);
	result.M43 = (m1->M41 * m2->M13) + (m1->M42 * m2->M23) + (m1->M43 * m2->M33) + (m1->M44 * m2->M43);
	result.M44 = (m1->M41 * m2->M14) + (m1->M42 * m2->M24) + (m1->M43 * m2->M34) + (m1->M44 * m2->M44);
	return result;
}

bool Matrix::Equals(Matrix other)
{
	return this->M11 == other.M11 && this->M22 == other.M22 && this->M33 == other.M33 && this->M44 == other.M44 && this->M12 == other.M12 && this->M13 == other.M13 && this->M14 == other.M14 && this->M21 == other.M21 && this->M23 == other.M23 && this->M24 == other.M24 && this->M31 == other.M31 && this->M32 == other.M32 && this->M34 == other.M34 && this->M41 == other.M41 && this->M42 == other.M42 && this->M43 == other.M43;
}

bool Matrix::operator ==(Matrix m2)
{
	return this->Equals(m2);
}

bool Matrix::operator !=(Matrix m2)
{
	return !this->Equals(m2);
}

Matrix Matrix::operator +(Matrix m2)
{
	return Matrix(this->M11 + m2.M11, this->M12 + m2.M12, this->M13 + m2.M13, this->M14 + m2.M14, this->M21 + m2.M21, this->M22 + m2.M22, this->M23 + m2.M23, this->M24 + m2.M24, this->M31 + m2.M31, this->M32 + m2.M32, this->M33 + m2.M33, this->M34 + m2.M34, this->M41 + m2.M41, this->M42 + m2.M42, this->M43 + m2.M43, this->M44 + m2.M44);
}

Matrix Matrix::operator -(Matrix m2)
{
	return Matrix(this->M11 - m2.M11, this->M12 - m2.M12, this->M13 - m2.M13, this->M14 - m2.M14, this->M21 - m2.M21, this->M22 - m2.M22, this->M23 - m2.M23, this->M24 - m2.M24, this->M31 - m2.M31, this->M32 - m2.M32, this->M33 - m2.M33, this->M34 - m2.M34, this->M41 - m2.M41, this->M42 - m2.M42, this->M43 - m2.M43, this->M44 - m2.M44);
}

Matrix Matrix::operator *(Matrix m2)
{
	Matrix result = Matrix::MultiplyRestricted(this, &m2);
	return result;
}

Matrix Matrix::operator *(float s)
{
	return Matrix(this->M11 * s, this->M12 * s, this->M13 * s, this->M14 * s, this->M21 * s, this->M22 * s, this->M23 * s, this->M24 * s, this->M31 * s, this->M32 * s, this->M33 * s, this->M34 * s, this->M41 * s, this->M42 * s, this->M43 * s, this->M44 * s);
}

Matrix Matrix::operator /(Matrix m2)
{
	return Matrix(this->M11 / m2.M11, this->M12 / m2.M12, this->M13 / m2.M13, this->M14 / m2.M14, this->M21 / m2.M21, this->M22 / m2.M22, this->M23 / m2.M23, this->M24 / m2.M24, this->M31 / m2.M31, this->M32 / m2.M32, this->M33 / m2.M33, this->M34 / m2.M34, this->M41 / m2.M41, this->M42 / m2.M42, this->M43 / m2.M43, this->M44 / m2.M44);
}

Matrix Matrix::operator /(float d)
{
	float num = 1.0f / d;
	return Matrix(this->M11 * num, this->M12 * num, this->M13 * num, this->M14 * num, this->M21 * num, this->M22 * num, this->M23 * num, this->M24 * num, this->M31 * num, this->M32 * num, this->M33 * num, this->M34 * num, this->M41 * num, this->M42 * num, this->M43 * num, this->M44 * num);
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