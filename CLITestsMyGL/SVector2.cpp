#include "SVector2.h"


// 带参数的构造函数
SVector2::SVector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

// 单一参数的构造函数
SVector2::SVector2(float v)
{
    this->x = v;
    this->y = v;
}

// 相等方法
bool SVector2::Equals(SVector2 other)
{
    return this->x == other.x && this->y == other.y;
}

// 加法运算符重载
SVector2 SVector2::operator +(SVector2 a, SVector2 b)
{
    return SVector2(a.x + b.x, a.y + b.y);
}

// 减法运算符重载
SVector2 SVector2::operator -(SVector2 a, SVector2 b)
{
    return SVector2(a.x - b.x, a.y - b.y);
}

// 乘法运算符重载
SVector2 SVector2::operator *(SVector2 a, SVector2 b)
{
    return SVector2(a.x * b.x, a.y * b.y);
}

// 等于运算符重载
bool SVector2::operator ==(SVector2 a, SVector2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}

// 不等于运算符重载
bool SVector2::operator !=(SVector2 a, SVector2 b)
{
    return !(a == b);
}

// GetHashCode 方法重写
int SVector2::GetHashCode()
{
    return this->x.GetHashCode() ^ this->y.GetHashCode();
}