#pragma once
#include "Vector3.h"

public ref struct SVector3
{
public:
    Vector3* vector3;

    // Properties for x, y, z
    property float X
    {
        float get() { return vector3->x; }
        void set(float value) { vector3->x = value; }
    }

    property float Y
    {
        float get() { return vector3->y; }
        void set(float value) { vector3->y = value; }
    }

    property float Z
    {
        float get() { return vector3->z; }
        void set(float value) { vector3->z = value; }
    }

    // Constructors
    SVector3();
    SVector3(float x, float y, float z);
    SVector3(float v);
    ~SVector3();

    bool Equals(SVector3 other);

    // Operator overloads
    static SVector3^ operator +(SVector3^ a, SVector3^ b);
    static SVector3^ operator -(SVector3^ a, SVector3^ b);
    static SVector3^ operator *(SVector3^ a, SVector3^ b);
    static SVector3^ operator *(SVector3^ a, float d);
    static SVector3^ operator /(SVector3^ a, SVector3^ b);
    static SVector3^ operator /(SVector3^ a, float d);
    static bool operator ==(SVector3^ a, SVector3^ b);
    static bool operator !=(SVector3^ a, SVector3^ b);

    // Methods
    virtual int GetHashCode() override;
};