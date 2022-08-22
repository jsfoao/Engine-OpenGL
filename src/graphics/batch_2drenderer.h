#pragma once
#include "renderer2d.h"
#include "vertex_array.h"

namespace Nata
{
	class Batch2DRenderer : Renderer2D
	{
	private:
		VertexArray m_VAO;
		unsigned int m_VBO;
		unsigned int m_IBO;

	public:
		void Submit(const Renderable2D* renderable) override;
		void Flush() override;
	};
}