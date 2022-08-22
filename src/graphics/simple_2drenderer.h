#pragma once
#include <deque>
#include "renderer2d.h"

namespace Nata
{
	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque<const Renderable2D*> m_RenderQueue;
	public:
		void Submit(const Renderable2D* renderable) override;
		void Flush() override;
	};
}