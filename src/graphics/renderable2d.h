#pragma once
#include "buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "shader.h"
#include "math/math.h"

namespace Nata
{
	class Renderable2D
	{
	protected:
		Vector3 m_Position;
		Vector2 m_Size;
		Vector4 m_Color;


		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;

		Shader* m_Shader;

	public:
		Renderable2D(Vector3 position, Vector2 size, Vector4 color, Shader* shader) 
			: m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)

		{
			m_VertexArray = new VertexArray();
			float vertices[]
			{
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
			};

			float colors[]
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			m_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

			unsigned short indices[] { 0, 1, 2, 2, 3, 0 };
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
		
		inline const Vector3 GetPosition() const { return m_Position; }
		inline const Vector2 GetSize() const { return m_Size; }
		inline const Vector4 GetColor() const { return m_Color; }

		void SetPosition(Vector3 position) { m_Position = position; }

		inline const VertexArray* GetVertexArray() const { return m_VertexArray; }
		inline const IndexBuffer* GetIndexBuffer() const { return m_IndexBuffer; }

		inline Shader* GetShader() const { return m_Shader; }
	};
}