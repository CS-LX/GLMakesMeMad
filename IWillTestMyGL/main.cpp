#include "GLWindow.h"
#include "GLShader.h"
#include "GLMesh.h"
#include "Vector3.h"


GLShader* shader;
GLMesh* mesh;
void OnInit()
{
	shader = GLShader::Load("VertexShader.vsh", "FragmentShader.psh");
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f
	};
	unsigned int indices[] = {
		// 注意索引从0开始! 
		// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
		// 这样可以由下标代表顶点组合成矩形

		0, 1, 2,
		0, 2, 3
	};
	mesh = new GLMesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
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
