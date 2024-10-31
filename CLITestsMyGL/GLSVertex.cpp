#include "GLSVertex.h"

GLSVertex::GLSVertex(SVector3 position, SColor color, SVector3 normal, SVector2 texCoord)
{
	this->Position = position;
	this->VertexColor = color;
	this->Normal = normal;
	this->TextureCoordinate = texCoord;
}