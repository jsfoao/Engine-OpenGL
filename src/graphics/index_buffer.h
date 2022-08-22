#pragma once
#include "GL/glew.h"

namespace Nata
{
	class IndexBuffer
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_Count;

	public:
		IndexBuffer(unsigned short* data, int count);

		void Bind() const;
		void Unbind() const;

		inline int GetCount() const { return m_Count; }
	};
}
