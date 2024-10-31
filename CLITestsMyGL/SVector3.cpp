#include "SVector3.h"

// Constructors
SVector3::SVector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

SVector3::SVector3(float v)
{
    this->x = this->y = this->z = v;
}

bool SVector3::Equals(SVector3 other)
{
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

// Addition operator overload
SVector3 SVector3::operator +(SVector3 a, SVector3 b)
{
    return SVector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

// Subtraction operator overload
SVector3 SVector3::operator -(SVector3 a, SVector3 b)
{
    return SVector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

// Multiplication with another vector
SVector3 SVector3::operator *(SVector3 a, SVector3 b)
{
    return SVector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

// Multiplication with a scalar
SVector3 SVector3::operator *(SVector3 a, float d)
{
    return SVector3(a.x * d, a.y * d, a.z * d);
}

// Division by another vector
SVector3 SVector3::operator /(SVector3 a, SVector3 b)
{
    return SVector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

// Division by a scalar
SVector3 SVector3::operator /(SVector3 a, float d)
{
    return SVector3(a.x / d, a.y / d, a.z / d);
}

// Equality operator overload
bool SVector3::operator ==(SVector3 a, SVector3 b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

// Inequality operator overload
bool SVector3::operator !=(SVector3 a, SVector3 b)
{
    return !(a == b);
}

// GetHashCode method override
int SVector3::GetHashCode()
{
    return x.GetHashCode() ^ y.GetHashCode() ^ z.GetHashCode();
}
