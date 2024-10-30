#include "SVector3.h"

// Constructors
SVector3::SVector3() : vector3(new Vector3()) {}
SVector3::SVector3(float x, float y, float z) : vector3(new Vector3(x, y, z)) {}
SVector3::SVector3(float v) : vector3(new Vector3(v)) {}
SVector3::~SVector3() { delete vector3; }

bool SVector3::Equals(SVector3 other)
{
    return vector3->Equals(*other.vector3); // 调用 Vector2 的 Equals 方法
}

// Addition operator overload
SVector3^ SVector3::operator +(SVector3^ a, SVector3^ b)
{
    return gcnew SVector3(a->vector3->x + b->vector3->x, a->vector3->y + b->vector3->y, a->vector3->z + b->vector3->z);
}

// Subtraction operator overload
SVector3^ SVector3::operator -(SVector3^ a, SVector3^ b)
{
    return gcnew SVector3(a->vector3->x - b->vector3->x, a->vector3->y - b->vector3->y, a->vector3->z - b->vector3->z);
}

// Multiplication with another vector
SVector3^ SVector3::operator *(SVector3^ a, SVector3^ b)
{
    return gcnew SVector3(a->vector3->x * b->vector3->x, a->vector3->y * b->vector3->y, a->vector3->z * b->vector3->z);
}

// Multiplication with a scalar
SVector3^ SVector3::operator *(SVector3^ a, float d)
{
    return gcnew SVector3(a->vector3->x * d, a->vector3->y * d, a->vector3->z * d);
}

// Division by another vector
SVector3^ SVector3::operator /(SVector3^ a, SVector3^ b)
{
    return gcnew SVector3(a->vector3->x / b->vector3->x, a->vector3->y / b->vector3->y, a->vector3->z / b->vector3->z);
}

// Division by a scalar
SVector3^ SVector3::operator /(SVector3^ a, float d)
{
    return gcnew SVector3(a->vector3->x / d, a->vector3->y / d, a->vector3->z / d);
}

// Equality operator overload
bool SVector3::operator ==(SVector3^ a, SVector3^ b)
{
    return a->vector3->x == b->vector3->x && a->vector3->y == b->vector3->y && a->vector3->z == b->vector3->z;
}

// Inequality operator overload
bool SVector3::operator !=(SVector3^ a, SVector3^ b)
{
    return !(a == b);
}

// GetHashCode method override
int SVector3::GetHashCode()
{
    return vector3->x.GetHashCode() ^ vector3->y.GetHashCode() ^ vector3->z.GetHashCode();
}
