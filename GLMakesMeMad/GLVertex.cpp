#include "GLVertex.h"

GLVertex::GLVertex(Vector3 position, Color color, Vector3 normal, Vector2 texCoord)
{
	this->Position = position;
	this->VertexColor = color;
	this->Normal = normal;
	this->TextureCoordinate = texCoord;
}