#pragma once
#include "GL/glew.h"
#include <iostream>
#include "core/core.h"
#include "utils/fileutils.h"
#include <vector>

namespace Nata
{
	class Shader
	{
	private:
		unsigned int m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;

	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void Enable() const;
		void Disable() const;
		
		unsigned int Load();
	};
}