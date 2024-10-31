#pragma once
#include "GLMesh.h"
#include "GLSVertex.h"
public ref class GLSMesh
{
public:
	GLMesh* mesh;

	GLSMesh(array<float>^ vertices, array<unsigned int>^ indices);
	GLSMesh(array<GLSVertex>^ vertices, array<unsigned int>^ indices);

	void Flush();

	~GLSMesh();
};

