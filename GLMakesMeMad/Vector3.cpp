#include "Vector3.h"

Vector3::Vector3()
{

	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{

	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(float v)
{
	this->x = v;
	this->y = v;
	this->z = v;
}

bool Vector3::Equals(Vector3 other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector3::operator ==(Vector3 v)
{
	return this->Equals(v);
}

bool Vector3::operator !=(Vector3 v)
{
	return !this->Equals(v);
}

Vector3 Vector3::operator +(Vector3 v)
{
	return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector3 Vector3::operator -(Vector3 v)
{
	return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector3 Vector3::operator *(Vector3 v)
{
	return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
}

Vector3 Vector3::operator *(float d)
{
	return Vector3(this->x * d, this->y * d, this->z * d);
}

Vector3 Vector3::operator /(Vector3 v)
{
	return Vector3(this->x / v.x, this->y / v.y, this->z / v.z);
}

Vector3 Vector3::operator /(float d)
{
	float num = 1.0f / d;
	return Vector3(this->x * num, this->y * num, this->z * num);
}