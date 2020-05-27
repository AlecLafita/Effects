#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderCommon.h"

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

	void ShaderProgram::Link()
	{
		glLinkProgram(mId);
		//TODO check errors
	}
}