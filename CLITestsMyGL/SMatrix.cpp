#include "SMatrix.h"

// 构造函数：初始化 nativeMatrix
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

// 拷贝构造函数（私有）
SMatrix::SMatrix(const Matrix& matrix)
    : nativeMatrix(new Matrix(matrix))
{
}

// 析构函数
SMatrix::~SMatrix()
{
    this->!SMatrix();
}

// 终结器
SMatrix::!SMatrix()
{
    delete nativeMatrix;
    nativeMatrix = nullptr;
}

// 静态属性 - 单位矩阵
SMatrix^ SMatrix::Identity()
{
    return gcnew SMatrix(Matrix::Identity());
}

// 静态属性 - 零矩阵
SMatrix^ SMatrix::Zero()
{
    return gcnew SMatrix(Matrix::Zero());
}

// 静态方法 - 从轴角创建矩阵
SMatrix^ SMatrix::CreateFromAxisAngle(SVector3^ axis, float angle)
{
    return gcnew SMatrix(Matrix::CreateFromAxisAngle(*axis->vector3, angle));
}

// 静态方法 - 创建正交矩阵
SMatrix^ SMatrix::CreateOrthographic(float width, float height, float nearPlane, float farPlane)
{
    return gcnew SMatrix(Matrix::CreateOrthographic(width, height, nearPlane, farPlane));
}

// 行列式
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

// 使用轴角创建旋转矩阵
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

// 使用缩放创建矩阵
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

// 使用平移创建矩阵
SMatrix^ SMatrix::CreateTranslation(float x, float y, float z)
{
    return gcnew SMatrix(Matrix::CreateTranslation(x, y, z));
}

SMatrix^ SMatrix::CreateTranslation(Vector3 position)
{
    return gcnew SMatrix(Matrix::CreateTranslation(position));
}

// 矩阵转置
SMatrix^ SMatrix::Transpose(SMatrix^ m)
{
    return gcnew SMatrix(Matrix::Transpose(*(m->nativeMatrix)));
}

// 矩阵求逆
SMatrix^ SMatrix::Invert(SMatrix^ m)
{
    return gcnew SMatrix(Matrix::Invert(*(m->nativeMatrix)));
}

// 矩阵线性插值
SMatrix^ SMatrix::Lerp(SMatrix^ m1, SMatrix^ m2, float f)
{
    return gcnew SMatrix(Matrix::Lerp(*(m1->nativeMatrix), *(m2->nativeMatrix), f));
}

// 矩阵乘法（受限）
SMatrix^ SMatrix::MultiplyRestricted(SMatrix^ m1, SMatrix^ m2)
{
    return gcnew SMatrix(Matrix::MultiplyRestricted(m1->nativeMatrix, m2->nativeMatrix));
}

// 运算符重载
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

// 比较运算符
bool SMatrix::operator==(SMatrix^ a, SMatrix^ b)
{
    return *(a->nativeMatrix) == *(b->nativeMatrix);
}

bool SMatrix::operator!=(SMatrix^ a, SMatrix^ b)
{
    return *(a->nativeMatrix) != *(b->nativeMatrix);
}

// 相等比较
bool SMatrix::Equals(SMatrix^ other)
{
    if (other == nullptr) return false;
    return *nativeMatrix == *(other->nativeMatrix);
}