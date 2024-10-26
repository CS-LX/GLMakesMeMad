#include "GLWindow.h"

int main()
{
	GLWindow::Init(800, 600, "AAA");

	while (true)
	{
		GLWindow::Render();
	}

	GLWindow::Close();
	return 0;
}