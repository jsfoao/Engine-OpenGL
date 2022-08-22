#include "shader.h"

namespace Nata
{
	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		m_VertPath = vertPath;
		m_FragPath = fragPath;

		m_ShaderID = Load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderID);
	}

	unsigned int Shader::GetUniformLocation(const char* name)
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

	void Shader::SetUniform1f(const char* name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniform1i(const char* name, int value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniform2f(const char* name, const Vector2& vector)
	{
		glUniform2f(GetUniformLocation(name), vector.x, vector.y);
	}

	void Shader::SetUniform3f(const char* name, const Vector3& vector)
	{
		glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
	}

	void Shader::SetUniform4f(const char* name, const Vector4& vector)
	{
		glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}

	void Shader::SetUniformMat4(const char* name, const Matrix4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}

	unsigned int Shader::Load()
	{
		unsigned int program = glCreateProgram();
		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string tempVertSource = FileUtils::ReadFile(m_VertPath);
		std::string tempFragSource = FileUtils::ReadFile(m_FragPath);

		const char* vertSource = tempVertSource.c_str();
		const char* fragSource = tempFragSource.c_str();

		// VERTEX
		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		// shader error handling
		int result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			LOG("Failed to compile vertex shader!");
			glDeleteShader(vertex);
			return 0;
		}

		// FRAGMENT
		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		// shader error handling
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			LOG("Failed to compile fragment shader!");
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	void Shader::Enable() const
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::Disable() const
	{
		glUseProgram(NULL);
	}
}