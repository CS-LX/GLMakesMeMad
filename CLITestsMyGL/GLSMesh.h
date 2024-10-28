#pragma once
#include "GLMesh.h"
public ref class GLSMesh
{
public:
	GLMesh* mesh;

	GLSMesh(array<float>^ vertices, array<unsigned int>^ indices);

	void Flush();

	~GLSMesh();
};

