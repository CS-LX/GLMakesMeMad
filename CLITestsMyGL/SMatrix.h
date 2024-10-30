#pragma once
#include "Matrix.h"
#include "SVector3.h"

public ref struct SMatrix
{
private:
    Matrix* nativeMatrix;
    SMatrix(const Matrix& matrix);
    !SMatrix();


public:
    // ���캯��
    SMatrix();
    SMatrix(float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44);

    // �����������ս���
    ~SMatrix();

    // ��̬����
    static SMatrix^ Identity();
    //0����
    static SMatrix^ Zero();
    //����ʽ
    float Determinant();
    //����ת�Ǵ���
    static SMatrix^ CreateFromAxisAngle(SVector3^ axis, float angle);
    //������������
    static SMatrix^ CreateOrthographic(float width, float height, float nearPlane, float farPlane);
    //ͨ�����Ĵ�����������
    static SMatrix^ CreateOrthographicOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
    //����͸�Ӿ���
    static SMatrix^ CreatePerspective(float width, float height, float nearPlane, float farPlane);
    //ͨ����Ұ����͸�Ӿ���
    static SMatrix^ CreatePerspectiveFieldOfView(float fieldOfViewY, float aspectRatio, float nearPlane, float farPlane);
    //ͨ�����Ĵ���͸�Ӿ���
    static SMatrix^ CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
    //��X����ת����
    static SMatrix^ CreateRotationX(float radians);
    //��Y����ת����
    static SMatrix^ CreateRotationY(float radians);
    //��Z����ת����
    static SMatrix^ CreateRotationZ(float radians);
    //���������Ŵ���
    static SMatrix^ CreateScale(float scale);
    //�����Ŵ���
    static SMatrix^ CreateScale(float x, float y, float z);
    //�����Ŵ���
    static SMatrix^ CreateScale(Vector3 scale);
    //��λ�ƴ���
    static SMatrix^ CreateTranslation(float x, float y, float z);
    //��λ�ƴ���
    static SMatrix^ CreateTranslation(Vector3 position);
    //ת��
    static SMatrix^ Transpose(SMatrix^ m);
    //����
    static SMatrix^ Invert(SMatrix^ m);
    //���Բ�ֵ
    static SMatrix^ Lerp(SMatrix^ m1, SMatrix^ m2, float f);
    //����˷�
    static SMatrix^ MultiplyRestricted(SMatrix^ m1, SMatrix^ m2);
    //���
    bool Equals(SMatrix^ other);

    // ����

    // ���������
    static SMatrix^ operator +(SMatrix^ a, SMatrix^ b);
    static SMatrix^ operator -(SMatrix^ a, SMatrix^ b);
    static SMatrix^ operator *(SMatrix^ a, SMatrix^ b);
    static SMatrix^ operator *(SMatrix^ a, float d);
    static SMatrix^ operator /(SMatrix^ a, SMatrix^ b);
    static SMatrix^ operator /(SMatrix^ a, float d);
    static bool operator ==(SMatrix^ a, SMatrix^ b);
    static bool operator !=(SMatrix^ a, SMatrix^ b);

    // ����Ԫ������
    property float M11
    {
        float get() { return nativeMatrix->M11; }
        void set(float value) { nativeMatrix->M11 = value; }
    }

    property float M12
    {
        float get() { return nativeMatrix->M12; }
        void set(float value) { nativeMatrix->M12 = value; }
    }

    property float M13
    {
        float get() { return nativeMatrix->M13; }
        void set(float value) { nativeMatrix->M13 = value; }
    }

    property float M14
    {
        float get() { return nativeMatrix->M14; }
        void set(float value) { nativeMatrix->M14 = value; }
    }

    property float M21
    {
        float get() { return nativeMatrix->M21; }
        void set(float value) { nativeMatrix->M21 = value; }
    }

    property float M22
    {
        float get() { return nativeMatrix->M22; }
        void set(float value) { nativeMatrix->M22 = value; }
    }

    property float M23
    {
        float get() { return nativeMatrix->M23; }
        void set(float value) { nativeMatrix->M23 = value; }
    }

    property float M24
    {
        float get() { return nativeMatrix->M24; }
        void set(float value) { nativeMatrix->M24 = value; }
    }

    property float M31
    {
        float get() { return nativeMatrix->M31; }
        void set(float value) { nativeMatrix->M31 = value; }
    }

    property float M32
    {
        float get() { return nativeMatrix->M32; }
        void set(float value) { nativeMatrix->M32 = value; }
    }

    property float M33
    {
        float get() { return nativeMatrix->M33; }
        void set(float value) { nativeMatrix->M33 = value; }
    }

    property float M34
    {
        float get() { return nativeMatrix->M34; }
        void set(float value) { nativeMatrix->M34 = value; }
    }

    property float M41
    {
        float get() { return nativeMatrix->M41; }
        void set(float value) { nativeMatrix->M41 = value; }
    }

    property float M42
    {
        float get() { return nativeMatrix->M42; }
        void set(float value) { nativeMatrix->M42 = value; }
    }

    property float M43
    {
        float get() { return nativeMatrix->M43; }
        void set(float value) { nativeMatrix->M43 = value; }
    }

    property float M44
    {
        float get() { return nativeMatrix->M44; }
        void set(float value) { nativeMatrix->M44 = value; }
    }
};

