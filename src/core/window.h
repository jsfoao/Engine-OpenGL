#pragma once
#include <iostream>
#include "core.h"
#include "core/input.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Nata
{
	class NATA_API Window
	{
	private:
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;

	public:
		Window(const char* name, int width, int height);
		~Window();
		void Update();
		bool Closed() const;
		void Clear() const;

		inline int GetWidth() const { return m_Width;  }
		inline int GetHeight() const { return m_Height;  }
		inline GLFWwindow* GetWindow() const { return m_Window; }
	private:
		bool Init();
	};

	static void handle_key_event(GLFWwindow* window, int key, int scancode, int action, int mods);
}