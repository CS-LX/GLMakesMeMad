#include "SVector2.h"


// �������Ĺ��캯��
SVector2::SVector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

// ��һ�����Ĺ��캯��
SVector2::SVector2(float v)
{
    this->x = v;
    this->y = v;
}

// ��ȷ���
bool SVector2::Equals(SVector2 other)
{
    return this->x == other.x && this->y == other.y;
}

// �ӷ����������
SVector2 SVector2::operator +(SVector2 a, SVector2 b)
{
    return SVector2(a.x + b.x, a.y + b.y);
}

// �������������
SVector2 SVector2::operator -(SVector2 a, SVector2 b)
{
    return SVector2(a.x - b.x, a.y - b.y);
}

// �˷����������
SVector2 SVector2::operator *(SVector2 a, SVector2 b)
{
    return SVector2(a.x * b.x, a.y * b.y);
}

// �������������
bool SVector2::operator ==(SVector2 a, SVector2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}

// ���������������
bool SVector2::operator !=(SVector2 a, SVector2 b)
{
    return !(a == b);
}

// GetHashCode ������д
int SVector2::GetHashCode()
{
    return this->x.GetHashCode() ^ this->y.GetHashCode();
}