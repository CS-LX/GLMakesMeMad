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