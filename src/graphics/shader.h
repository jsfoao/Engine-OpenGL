#pragma once
#include "GL/glew.h"
#include <iostream>
#include "core/core.h"
#include "utils/fileutils.h"
#include <vector>
#include "math/math.h"

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
		inline unsigned int GetID() { return m_ShaderID; }


		void SetUniform1f(const char* name, float value);
		void SetUniform1i(const char* name, int value);
		void SetUniform2f(const char* name, const Vector2& vector);
		void SetUniform3f(const char* name, const Vector3& vector);
		void SetUniform4f(const char* name, const Vector4& vector);
		void SetUniformMat4(const char* name, const Matrix4& matrix);
		
		unsigned int Load();

	private:
		unsigned int GetUniformLocation(const char* name);
	};
}