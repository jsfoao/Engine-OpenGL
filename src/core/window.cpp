#include "window.h"

namespace Nata
{
	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		if (!Init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to created window!\n" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		return true;

	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}