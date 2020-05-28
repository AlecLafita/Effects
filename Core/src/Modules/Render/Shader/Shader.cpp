#include "Shader.h"
#include <vector>
#include <iostream>

namespace effectsEngine
{
	Shader::Shader(eShaderType aShaderType, const char* aSource) : 
		mSource(aSource)
	{
		GLenum shaderType;
		switch (aShaderType)
		{
			case eShaderType::Vertex:
				shaderType = GL_VERTEX_SHADER;
			break;
			case eShaderType::Fragment:
				shaderType = GL_FRAGMENT_SHADER;
			break;
			default:
				//TODO exception
			break;
		}
		mId = glCreateShader(shaderType);
	}

	Shader::~Shader()
	{
		glDeleteShader(mId);
	}

	unsigned int Shader::GetId() const
	{
		return mId;
	}

	bool Shader::Compile()
	{
		glShaderSource(mId, 1, &mSource, nullptr); //TODO includes, etc
		glCompileShader(mId);
		
		GLint isCompiled = 0;
		glGetShaderiv(mId, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(mId, GL_INFO_LOG_LENGTH, &maxLength);

			std::string infoLog;
			infoLog.resize(maxLength);
			glGetShaderInfoLog(mId, maxLength, &maxLength, &infoLog[0]);
			std::cout << infoLog << std::endl;

			glDeleteShader(mId);
			return false;
		}
		return true;
	}
}