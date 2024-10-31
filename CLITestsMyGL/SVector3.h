#pragma once
#include "Vector3.h"

public value struct SVector3
{
public:
    float x;
    float y;
    float z;

    // Constructors
    SVector3(float x, float y, float z);
    SVector3(float v);

    bool Equals(SVector3 other);

    // Operator overloads
    static SVector3 operator +(SVector3 a, SVector3 b);
    static SVector3 operator -(SVector3 a, SVector3 b);
    static SVector3 operator *(SVector3 a, SVector3 b);
    static SVector3 operator *(SVector3 a, float d);
    static SVector3 operator /(SVector3 a, SVector3 b);
    static SVector3 operator /(SVector3 a, float d);
    static bool operator ==(SVector3 a, SVector3 b);
    static bool operator !=(SVector3 a, SVector3 b);

    // Methods
    virtual int GetHashCode() override;
};
