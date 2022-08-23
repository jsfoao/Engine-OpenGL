#pragma once
#include "renderer2d.h"
#include "vertex_array.h"
#include "index_buffer.h"

namespace Nata
{
#define RENDERER_MAX_OBJECTS	10000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_OBJECT_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_OBJECT_SIZE * RENDERER_MAX_OBJECTS
#define RENDERER_INDICES_SIZE	RENDERER_MAX_OBJECTS * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

	class Batch2DRenderer : Renderer2D
	{
	private:
		unsigned int m_VAO;
		unsigned int m_VBO;
		IndexBuffer* m_IBO;
		unsigned int m_IndexCount;

	public:
		Batch2DRenderer();
		~Batch2DRenderer();
		void Submit(const Renderable2D* renderable) override;
		void Flush() override;

	private:
		void Init();
	};
}