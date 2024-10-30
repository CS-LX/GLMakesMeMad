#include "SMatrix.h"

// ���캯������ʼ�� nativeMatrix
SMatrix::SMatrix()
    : nativeMatrix(new Matrix())
{
}

SMatrix::SMatrix(float m11, float m12, float m13, float m14,
    float m21, float m22, float m23, float m24,
    float m31, float m32, float m33, float m34,
    float m41, float m42, float m43, float m44)
    : nativeMatrix(new Matrix(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44))
{
}

// �������캯����˽�У�
SMatrix::SMatrix(const Matrix& matrix)
    : nativeMatrix(new Matrix(matrix))
{
}

// ��������
SMatrix::~SMatrix()
{
    this->!SMatrix();
}

// �ս���
SMatrix::!SMatrix()
{
    delete nativeMatrix;
    nativeMatrix = nullptr;
}

// ��̬���� - ��λ����
SMatrix^ SMatrix::Identity()
{
    return gcnew SMatrix(Matrix::Identity());
}

// ��̬���� - �����
SMatrix^ SMatrix::Zero()
{
    return gcnew SMatrix(Matrix::Zero());
}

// ��̬���� - ����Ǵ�������
SMatrix^ SMatrix::CreateFromAxisAngle(SVector3^ axis, float angle)
{
    return gcnew SMatrix(Matrix::CreateFromAxisAngle(*axis->vector3, angle));
}

// ��̬���� - ������������
SMatrix^ SMatrix::CreateOrthographic(float width, float height, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreateOrthographic(width, height, nearPlane, farPlane));
}

// ����ʽ
float SMatrix::Determinant()
{
    return nativeMatrix->Determinant();
}

SMatrix^ SMatrix::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreateOrthographicOffCenter(left, right, bottom, top, nearPlane, farPlane));
}

SMatrix^ SMatrix::CreatePerspective(float width, float height, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreatePerspective(width, height, nearPlane, farPlane));
}

SMatrix^ SMatrix::CreatePerspectiveFieldOfView(float fieldOfViewY, float aspectRatio, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreatePerspectiveFieldOfView(fieldOfViewY, aspectRatio, nearPlane, farPlane));
}

SMatrix^ SMatrix::CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreatePerspectiveOffCenter(left, right, bottom, top, nearPlane, farPlane));
}

// ʹ����Ǵ�����ת����
SMatrix^ SMatrix::CreateRotationX(float radians)
{
    return gcnew SMatrix(Matrix::CreateRotationX(radians));
}

SMatrix^ SMatrix::CreateRotationY(float radians)
{
    return gcnew SMatrix(Matrix::CreateRotationY(radians));
}

SMatrix^ SMatrix::CreateRotationZ(float radians)
{
    return gcnew SMatrix(Matrix::CreateRotationZ(radians));
}

// ʹ�����Ŵ�������
SMatrix^ SMatrix::CreateScale(float scale)
{
    return gcnew SMatrix(Matrix::CreateScale(scale));
}

SMatrix^ SMatrix::CreateScale(float x, float y, float z)
{
    return gcnew SMatrix(Matrix::CreateScale(x, y, z));
}

SMatrix^ SMatrix::CreateScale(Vector3 scale)
{
    return gcnew SMatrix(Matrix::CreateScale(scale));
}

// ʹ��ƽ�ƴ�������
SMatrix^ SMatrix::CreateTranslation(float x, float y, float z)
{
    return gcnew SMatrix(Matrix::CreateTranslation(x, y, z));
}

SMatrix^ SMatrix::CreateTranslation(Vector3 position)
{
    return gcnew SMatrix(Matrix::CreateTranslation(position));
}

// ����ת��
SMatrix^ SMatrix::Transpose(SMatrix^ m)
{
    return gcnew SMatrix(Matrix::Transpose(*(m->nativeMatrix)));
}

// ��������
SMatrix^ SMatrix::Invert(SMatrix^ m)
{
    return gcnew SMatrix(Matrix::Invert(*(m->nativeMatrix)));
}

// �������Բ�ֵ
SMatrix^ SMatrix::Lerp(SMatrix^ m1, SMatrix^ m2, float f)
{
    return gcnew SMatrix(Matrix::Lerp(*(m1->nativeMatrix), *(m2->nativeMatrix), f));
}

// ����˷������ޣ�
SMatrix^ SMatrix::MultiplyRestricted(SMatrix^ m1, SMatrix^ m2)
{
    return gcnew SMatrix(Matrix::MultiplyRestricted(m1->nativeMatrix, m2->nativeMatrix));
}

// ���������
SMatrix^ SMatrix::operator+(SMatrix^ a, SMatrix^ b)
{
    return gcnew SMatrix(*(a->nativeMatrix) + *(b->nativeMatrix));
}

SMatrix^ SMatrix::operator-(SMatrix^ a, SMatrix^ b)
{
    return gcnew SMatrix(*(a->nativeMatrix) - *(b->nativeMatrix));
}

SMatrix^ SMatrix::operator*(SMatrix^ a, SMatrix^ b)
{
    return gcnew SMatrix(*(a->nativeMatrix) * *(b->nativeMatrix));
}

SMatrix^ SMatrix::operator*(SMatrix^ a, float d)
{
    return gcnew SMatrix(*(a->nativeMatrix) * d);
}

SMatrix^ SMatrix::operator/(SMatrix^ a, SMatrix^ b)
{
    return gcnew SMatrix(*(a->nativeMatrix) / *(b->nativeMatrix));
}

SMatrix^ SMatrix::operator/(SMatrix^ a, float d)
{
    return gcnew SMatrix(*(a->nativeMatrix) / d);
}

// �Ƚ������
bool SMatrix::operator==(SMatrix^ a, SMatrix^ b)
{
    return *(a->nativeMatrix) == *(b->nativeMatrix);
}

bool SMatrix::operator!=(SMatrix^ a, SMatrix^ b)
{
    return *(a->nativeMatrix) != *(b->nativeMatrix);
}

// ��ȱȽ�
bool SMatrix::Equals(SMatrix^ other)
{
    if (other == nullptr) return false;
    return *nativeMatrix == *(other->nativeMatrix);
}