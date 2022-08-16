#pragma once
#include <iostream>
#include "GLFW/glfw3.h"

namespace Nata
{
	class Window
	{
	private:
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;
	public:
		Window(const char* name, int width, int height);
		~Window();
		void Update() const;
	private:
		bool Init();
		bool Closed() const;
	};
}