#include "input.h"

namespace Nata
{
	bool Input::keys[GLFW_KEY_LAST];
	bool Input::mouseBtns[MAX_MOUSE_BUTTONS];

	Input::Input()
	{
		for (size_t i = 0; i < (int)Key::MAX; i++)
		{
			keys[i] = false;
		}

		for (size_t i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			mouseBtns[i] = false;
		}
	}

	void Input::Init()
	{
	}

	bool Input::GetKeyDown(int key)
	{
		if (key >= GLFW_KEY_LAST)
			return false;

		return keys[key] == true;
	}


	bool Input::GetMouseButtonDown(int button)
	{
		if (button >= MAX_MOUSE_BUTTONS)
			return false;
		
		return mouseBtns[button] == true;
	}

	void Input::SetKeyState(int key, bool state)
	{
		keys[key] = state;
	}

	void Input::SetMouseState(int mouseBtn, bool state)
	{
		mouseBtns[mouseBtn] = state;
	}
}