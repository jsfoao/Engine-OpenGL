#pragma once
#include <iostream>
#include "core.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "key.h"
#include "math/vector.h"

namespace Nata
{
#define MAX_MOUSE_BUTTONS 32
	
	struct ActionState
	{
		bool current;
		bool previous;
	};

	class Input
	{
	public:
		ActionState keys[GLFW_KEY_LAST];
		ActionState mouseBtns[MAX_MOUSE_BUTTONS];
		double mx;
		double my;

	public:
		Input();
		~Input();
		void Init();
		void Clear();

		bool GetKeyDown(int key) const;
		//bool GetKeyRelease(int key) const;
		//bool GetKeyHold(int key) const;

		bool GetMouseDown(int button) const;
		//bool GetMouseRelease(int button) const;
		//bool GetMouseHold(int button) const;

		void SetKeyState(int key, bool state);
		void SetMouseState(int mouseBtn, bool state);
		void SetCursorPos(double x, double y);

		Vector2 GetMousePos() { return Vector2(mx, my); }
	};

	extern Input* input;
}