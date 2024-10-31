#pragma once
#include "SVector3.h"
#include "SVector2.h"
#include "SColor.h"
public value struct GLSVertex
{
public:
	SVector3 Position;
	SColor VertexColor;
	SVector3 Normal;
	SVector2 TextureCoordinate;

	GLSVertex(SVector3 position, SColor color, SVector3 normal, SVector2 texCoord);
};

