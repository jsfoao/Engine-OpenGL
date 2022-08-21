#include "window.h"

namespace Nata
{
	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		failed = false;

		if (!Init())
		{
			failed = true;
			glfwTerminate();
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			LOG("Failed to initialize GLFW!");
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			LOG("Failed to created window!");
			return false;
		}
		glfwMakeContextCurrent(m_Window);

		if (!glewInit())
		{
			LOG("Failed to initialize GLEW!");
			return false;
		}

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, key_callback); 
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_pos_callback);

		m_Input = new Input();

		if (!m_Input)
		{
			LOG("Failed to create input!");
		}

		return true;
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	void Window::Update()
	{
		glfwPollEvents();

		// changed window size
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);

		// stretch contents depending on window size
		glViewport(0, 0, m_Width, m_Height);
		glfwSwapBuffers(m_Window);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->GetInput()->SetKeyState(key, action != GLFW_RELEASE);
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->GetInput()->SetMouseState(button, action != GLFW_RELEASE);
	}

	void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->GetInput()->SetCursorPos(xpos, ypos);
	}
}