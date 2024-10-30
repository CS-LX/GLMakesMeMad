#include "Vector2.h"

Vector2::Vector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(float v)
{
	this->x = v;
	this->y = v;
}

bool Vector2::Equals(Vector2 other)
{
	return this->x == other.x && this->y == other.y;
}

bool Vector2::operator ==(Vector2 v)
{
	return this->Equals(v);
}

bool Vector2::operator !=(Vector2 v)
{
	return !this->Equals(v);
}

Vector2 Vector2::operator +(Vector2 v)
{
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator -(Vector2 v)
{
	return Vector2(this->x - v.x, this->y - v.y);
}

Vector2 Vector2::operator *(Vector2 v)
{
	return Vector2(this->x * v.x, this->y * v.y);
}

Vector2 Vector2::operator *(float d)
{
	return Vector2(this->x * d, this->y * d);
}

Vector2 Vector2::operator /(Vector2 v)
{
	return Vector2(this->x / v.x, this->y / v.y);
}

Vector2 Vector2::operator /(float d)
{
	float num = 1.0f / d;
	return Vector2(this->x * num, this->y * num);
}