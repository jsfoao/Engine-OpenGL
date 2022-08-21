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