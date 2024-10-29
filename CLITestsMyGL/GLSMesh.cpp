#include "GLSMesh.h"

GLSMesh::GLSMesh(array<float>^ vertices, array<unsigned int>^ indices)
{
	std::vector<float> verticesRaw;
	std::vector<unsigned int> indicesRaw;
	for each (float vertex in vertices)
	{
		verticesRaw.push_back(vertex);
	}
	for each (unsigned int index in indices)
	{
		indicesRaw.push_back(index);
	}
	mesh = new GLMesh(verticesRaw, indicesRaw);
}

void GLSMesh::Flush()
{
	mesh->Flush();
}

GLSMesh::~GLSMesh()
{
	mesh->~GLMesh();
	delete mesh;
}