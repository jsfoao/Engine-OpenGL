#pragma once
#include "GL/glew.h"
#include "math/math.h"
#include "renderable2d.h"

namespace Nata
{
	class Renderer2D
	{
	protected:
		virtual void Submit(const Renderable2D* renderable) = 0;
		virtual void Flush() = 0;
	};
}