#pragma once
#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"

struct DLL_API GLVertex
{
public:
	Vector3 Position;
	Color VertexColor;
	Vector3 Normal;
	Vector2 TextureCoordinate;

	GLVertex(Vector3 position, Color color, Vector3 normal, Vector2 texCoord);
};

