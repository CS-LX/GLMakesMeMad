#include "GLWindow.h"


void OnInit()
{

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
