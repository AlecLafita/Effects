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

	void ShaderProgram::Activate(bool aActivate)
	{
		glUseProgram(aActivate ? mId : 0U);
	}

	void ShaderProgram::SetInt(const std::string& aName, int aValue)
	{
		glUniform1i(glGetUniformLocation(mId, aName.c_str()), aValue);
	}

	void ShaderProgram::SetFloat(const std::string& aName, float aValue)
	{
		glUniform1f(glGetUniformLocation(mId, aName.c_str()), aValue);
	}

	void ShaderProgram::SetVec4f(const std::string& aName, const glm::vec4& aValue)
	{
		glUniform4f(glGetUniformLocation(mId, aName.c_str()), aValue.x, aValue.y, aValue.z, aValue.w);
	}

}