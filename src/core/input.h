#pragma once
#include <iostream>
#include "core.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "key.h"

namespace Nata
{
#define MAX_MOUSE_BUTTONS 32
	class NATA_API Input
	{
	public:
		static bool keys[GLFW_KEY_LAST];
		static bool mouseBtns[MAX_MOUSE_BUTTONS];
		double mx, my;

	public:
		Input();
		~Input();
		void Init();
		void Clear();

		static bool GetKeyDown(int key);
		static bool GetKeyRelease(int key);
		static bool GetKeyHold(int key);

		static bool GetMouseButtonDown(int button);

		static void SetKeyState(int key, bool state);
		static void SetMouseState(int mouseBtn, bool state);
	};
}