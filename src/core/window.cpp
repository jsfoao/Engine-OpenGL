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
			LOG("Failed to initialize GLFW!")
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

		if (glewInit() != GLEW_OK)
		{
			LOG("Could not initialize GLEW!");
		}

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, handle_key_event); 

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

	void handle_key_event(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		Input::SetKeyState(key, action);
	}

	void handle_mouse_event(GLFWwindow* window, int button, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		Input::SetMouseState(button, action);
	}
}