#include "input.h"

namespace Nata
{
	Input::Input()
	{
		mx = 0;
		my = 0;

		for (size_t i = 0; i < GLFW_KEY_LAST; i++)
		{
			keys[i].current = false;
			keys[i].previous = false;
		}

		for (size_t i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			mouseBtns[i].current = false;
			mouseBtns[i].previous = false;
		}
	}

	void Input::Init()
	{
	}

	bool Input::GetKeyDown(int code) const
	{
		if (code >= GLFW_KEY_LAST)
			return false;

		return keys[code].current;
	}


	bool Input::GetMouseDown(int code) const
	{
		if (code >= MAX_MOUSE_BUTTONS)
			return false;
		
		return mouseBtns[code].current;
	}

	void Input::SetKeyState(int code, bool state)
	{
		keys[code].previous = keys[code].current;
		keys[code].current = state;
	}

	void Input::SetMouseState(int code, bool state)
	{
		keys[code].previous = keys[code].current;
		mouseBtns[code].current = state;
	}
	void Input::SetCursorPos(double x, double y)
	{
		mx = x;
		my = y;
	}
}