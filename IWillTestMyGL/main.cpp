#include "GLWindow.h"
#include "GLVertexShader.h"
#include "GLFragmentShader.h"


void OnInit()
{
	GLVertexShader* vsh = new GLVertexShader("AAA");
	GLFragmentShader* psh = new GLFragmentShader("BBB");
}

void OnRendering()
{

}

void OnClosing()
{

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
