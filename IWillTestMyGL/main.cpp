#include "GLWindow.h"
#include "GLShader.h"
#include "GLMesh.h"
#include "Vector3.h"
#include "GLVertex.h"
#include <iostream>
#include <windows.h>

GLShader* shader;
GLMesh* mesh;
void OnInit()
{
	shader = GLShader::Load("VertexShader.vsh", "FragmentShader.psh");
	std::vector<GLVertex> vertices;
	vertices.push_back(GLVertex(Vector3(-0.5f, -0.5f, 0.0f), Color(0.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector2(0.0f, 0.0f)));
	vertices.push_back(GLVertex(Vector3(-0.5f, 0.5f, 0.0f), Color(0.0f, 1.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector2(0.0f, 1.0f)));
	vertices.push_back(GLVertex(Vector3(0.5f, 0.5f, 0.0f), Color(1.0f, 1.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector2(1.0f, 1.0f)));
	vertices.push_back(GLVertex(Vector3(0.5f, -0.5f, 0.0f), Color(1.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector2(1.0f, 0.0f)));

	std::vector<unsigned int> indices = {0, 1, 2, 0, 2, 3};

	mesh = new GLMesh(vertices, indices);
}

void OnRendering()
{
	DWORD milliseconds = GetTickCount64();
	milliseconds %= 100000;
	Matrix m1 = Matrix::CreateScale(0.8f, 1.5f, 1.0f);
	Matrix m2 = Matrix::CreateRotationZ(3.1415926f / 4.0f);
	Matrix m3 = Matrix::CreateTranslation(0, 1, 0);
	m2 = m2 * m3;
	shader->Use();
	shader->SetMatrix("u_Matrix", Matrix::Lerp(m1, m2, sin(static_cast<float>(milliseconds) / 1000.0f) * 0.5f + 0.5f));
	mesh->Flush();
}

void OnClosing()
{
	delete shader;
	delete mesh;
}

void OnMouseMoving(float xPos, float yPos)
{
}

void OnScrollRolling(float xOffset, float yOffset)
{
}

int main()
{
	GLWindow::RegisterOnInit(OnInit);
	GLWindow::RegisterOnRendering(OnRendering);
	GLWindow::RegisterOnClosing(OnClosing);
	GLWindow::RegisterOnMouseMoving(OnMouseMoving);
	GLWindow::RegisterOnScrollRolling(OnScrollRolling);
	GLWindow::Init(800, 800, "AAA");

	while (!GLWindow::ShouldClose())
	{
		GLWindow::Render();
	}

	GLWindow::Close();
	return 0;
}
