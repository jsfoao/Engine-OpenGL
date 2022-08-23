#pragma once
#include "renderable2d.h"

namespace Nata
{
	class StaticSprite : public Renderable2D
	{
	private:
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader* m_Shader;
	public:
		StaticSprite();
	};
}