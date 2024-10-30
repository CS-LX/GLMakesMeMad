#include "SVector2.h"

// 默认构造函数
SVector2::SVector2()
{
    vector2 = new Vector2(); // 创建一个 Vector2 的实例
}

// 带参数的构造函数
SVector2::SVector2(float x, float y)
{
    vector2 = new Vector2(x, y); // 创建一个 Vector2 的实例并初始化
}

// 单一参数的构造函数
SVector2::SVector2(float v)
{
    vector2 = new Vector2(v); // 创建一个 Vector2 的实例并初始化
}

SVector2::SVector2(const SVector2% other)
{
    vector2 = new Vector2(other.vector2->x, other.vector2->y);
}

SVector2::SVector2(const Vector2& vec)
{
    vector2 = new Vector2(vec.x, vec.y); // 使用 Vector2 的 x 和 y 初始化
}


// 析构函数
SVector2::~SVector2()
{
    delete vector2; // 释放 Vector2 的实例
}

// 相等方法
bool SVector2::Equals(SVector2 other)
{
    return vector2->Equals(*other.vector2); // 调用 Vector2 的 Equals 方法
}

// 加法运算符重载
SVector2^ SVector2::operator +(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x + b->vector2->x, a->vector2->y + b->vector2->y);
}

// 减法运算符重载
SVector2^ SVector2::operator -(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x - b->vector2->x, a->vector2->y - b->vector2->y);
}

// 乘法运算符重载
SVector2^ SVector2::operator *(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x * b->vector2->x, a->vector2->y * b->vector2->y);
}

// 等于运算符重载
bool SVector2::operator ==(SVector2^ a, SVector2^ b)
{
    return (a->vector2->x == b->vector2->x) && (a->vector2->y == b->vector2->y);
}

// 不等于运算符重载
bool SVector2::operator !=(SVector2^ a, SVector2^ b)
{
    return !(a == b);
}

// GetHashCode 方法重写
int SVector2::GetHashCode()
{
    return vector2->x.GetHashCode() ^ vector2->y.GetHashCode();
}