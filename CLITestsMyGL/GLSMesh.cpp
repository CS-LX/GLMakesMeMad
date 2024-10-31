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

GLSMesh::GLSMesh(array<GLSVertex>^ vertices, array<unsigned int>^ indices)
{
	std::vector<float> verticesRaw;
	std::vector<unsigned int> indicesRaw;
	for (int i = 0; i < vertices->Length; ++i)
	{
		verticesRaw.push_back(static_cast<float>(vertices[i].Position.x));
		verticesRaw.push_back(static_cast<float>(vertices[i].Position.y));
		verticesRaw.push_back(static_cast<float>(vertices[i].Position.z));
		verticesRaw.push_back(static_cast<float>(vertices[i].VertexColor.r));
		verticesRaw.push_back(static_cast<float>(vertices[i].VertexColor.g));
		verticesRaw.push_back(static_cast<float>(vertices[i].VertexColor.b));
		verticesRaw.push_back(static_cast<float>(vertices[i].VertexColor.a));
		verticesRaw.push_back(static_cast<float>(vertices[i].Normal.x));
		verticesRaw.push_back(static_cast<float>(vertices[i].Normal.y));
		verticesRaw.push_back(static_cast<float>(vertices[i].Normal.z));
		verticesRaw.push_back(static_cast<float>(vertices[i].TextureCoordinate.x));
		verticesRaw.push_back(static_cast<float>(vertices[i].TextureCoordinate.y));
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