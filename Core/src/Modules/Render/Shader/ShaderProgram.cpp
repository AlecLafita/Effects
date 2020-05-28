#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderCommon.h"
#include <vector>
#include <iostream>

namespace effectsEngine
{
	ShaderProgram::ShaderProgram()
	{
		mId = glCreateProgram();
	}

	ShaderProgram::~ShaderProgram()
	{
	}

	unsigned int ShaderProgram::GetId() const
	{
		return mId;
	}

	void ShaderProgram::AttachShader(const Shader& aShader)
	{
		glAttachShader(mId, aShader.GetId());
	}

	bool ShaderProgram::Link()
	{
		glLinkProgram(mId);
		
		GLint isLinked = 0;
		glGetProgramiv(mId, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &maxLength);

			std::string infoLog;
			infoLog.resize(maxLength);
			glGetProgramInfoLog(mId, maxLength, &maxLength, &infoLog[0]);
			std::cout << infoLog << std::endl;

			glDeleteProgram(mId);

			return false;
		}
		return true;
	}
}