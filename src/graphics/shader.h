#pragma once
#include "GL/glew.h"
#include "utils/fileutils.h"
#include <iostream>
#include "core/core.h"
#include <vector>

namespace Nata
{
	class NATA_API Shader
	{
	private:
		// shader id
		unsigned int m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;

	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void Enable() const;
		void Disable() const;
		
		// id getter
		unsigned int Load();
	};
}