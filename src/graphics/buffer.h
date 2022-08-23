#pragma once
#include "GL/glew.h"

namespace Nata
{
	class Buffer
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_ComponentCount;

	public:
		Buffer(float* data, int count, int componentCount);
		~Buffer();

		void Bind() const;
		void Unbind() const;

		inline int GetComponentCount() const { return m_ComponentCount; }
	};
}
