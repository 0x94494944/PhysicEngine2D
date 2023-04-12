#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(700, 600, "init", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "error, something wrong happened!" << '\n';

	std::cout << glGetString(GL_VERSION) << "\n";

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0); // red
		glVertex2d(0.0f, 0.5f);

		glColor3f(0, 1, 0); // green
		glVertex2d(-0.5f, -0.5f);

		glColor3f(0, 0, 1); // blue
		glVertex2d(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}