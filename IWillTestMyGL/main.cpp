#include "GLWindow.h"
#include "GLShader.h"
#include "GLMesh.h"
#include "Vector3.h"
#include "GLVertex.h"


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
	shader->Use();
	mesh->Flush();
}

void OnClosing()
{
	delete shader;
	delete mesh;
}

int main()
{
	GLWindow::RegisterOnInit(OnInit);
	GLWindow::RegisterOnRendering(OnRendering);
	GLWindow::RegisterOnClosing(OnClosing);
	GLWindow::Init(800, 600, "AAA");

	while (!GLWindow::ShouldClose())
	{
		GLWindow::Render();
	}

	GLWindow::Close();
	return 0;
}
