#include "simple_2drenderer.h"

namespace Nata
{
	void Simple2DRenderer::Submit(const Renderable2D* renderable)
	{
		m_RenderQueue.push_back(renderable);
	}

	void Simple2DRenderer::Flush()
	{
		while (!m_RenderQueue.empty())
		{
			const Renderable2D* renderable = m_RenderQueue.front();
			renderable->GetVertexArray()->Bind();
			renderable->GetIndexBuffer()->Bind();

			renderable->GetShader()->SetUniformMat4("ml_matrix", Matrix4::Translation(renderable->GetPosition()));
			glDrawElements(GL_TRIANGLES, renderable->GetIndexBuffer()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

			renderable->GetIndexBuffer()->Unbind();
			renderable->GetVertexArray()->Unbind();

			m_RenderQueue.pop_front();
		}
	}
}