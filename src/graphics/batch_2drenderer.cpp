#include "batch_2drenderer.h"

namespace Nata
{
	Batch2DRenderer::Batch2DRenderer()
	{
		Init();
	}

	Batch2DRenderer::~Batch2DRenderer()
	{
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
	}

	void Batch2DRenderer::Init()
	{
		// Generating arrays and buffers ID
		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);

		// Note on binding: Avoid doing too often since it's costly method
		// BINDING BUFFER
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		// GL_DYNAMIC_DRAW means data will be modified repeatedly and used many times
		// Create data store with size of renderer buffer
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		// Attributes for each vertex data element: vertex and color
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3*GL_FLOAT));

		// Enable so it can be used for rendering when calling glDrawArray or glDrawElements
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		// UNBINDING BUFFER
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		unsigned short indices[RENDERER_INDICES_SIZE];

		int offset = 0;
		for (size_t i = 0; i < RENDERER_INDICES_SIZE; i+=6)
		{
			indices[  i	 ] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		// Unbind Vertex Array
		glBindVertexArray(0);
	}

	void Batch2DRenderer::Submit(const Renderable2D* renderable)
	{

	}

	void Batch2DRenderer::Flush()
	{
	}
}