#include "SVector2.h"

// Ĭ�Ϲ��캯��
SVector2::SVector2()
{
    vector2 = new Vector2(); // ����һ�� Vector2 ��ʵ��
}

// �������Ĺ��캯��
SVector2::SVector2(float x, float y)
{
    vector2 = new Vector2(x, y); // ����һ�� Vector2 ��ʵ������ʼ��
}

// ��һ�����Ĺ��캯��
SVector2::SVector2(float v)
{
    vector2 = new Vector2(v); // ����һ�� Vector2 ��ʵ������ʼ��
}

SVector2::SVector2(const SVector2% other)
{
    vector2 = new Vector2(other.vector2->x, other.vector2->y);
}

SVector2::SVector2(const Vector2& vec)
{
    vector2 = new Vector2(vec.x, vec.y); // ʹ�� Vector2 �� x �� y ��ʼ��
}


// ��������
SVector2::~SVector2()
{
    delete vector2; // �ͷ� Vector2 ��ʵ��
}

// ��ȷ���
bool SVector2::Equals(SVector2 other)
{
    return vector2->Equals(*other.vector2); // ���� Vector2 �� Equals ����
}

// �ӷ����������
SVector2^ SVector2::operator +(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x + b->vector2->x, a->vector2->y + b->vector2->y);
}

// �������������
SVector2^ SVector2::operator -(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x - b->vector2->x, a->vector2->y - b->vector2->y);
}

// �˷����������
SVector2^ SVector2::operator *(SVector2^ a, SVector2^ b)
{
    return gcnew SVector2(a->vector2->x * b->vector2->x, a->vector2->y * b->vector2->y);
}

// �������������
bool SVector2::operator ==(SVector2^ a, SVector2^ b)
{
    return (a->vector2->x == b->vector2->x) && (a->vector2->y == b->vector2->y);
}

// ���������������
bool SVector2::operator !=(SVector2^ a, SVector2^ b)
{
    return !(a == b);
}

// GetHashCode ������д
int SVector2::GetHashCode()
{
    return vector2->x.GetHashCode() ^ vector2->y.GetHashCode();
}