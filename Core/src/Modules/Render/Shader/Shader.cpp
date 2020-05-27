#include "Shader.h"

namespace effectsEngine
{
	Shader::Shader(eShaderType aShaderType, const char* aSource) : 
		mSource(aSource)
	{
		mId = glCreateShader(static_cast<GLenum>(aShaderType));
	}

	Shader::~Shader()
	{
		glDeleteShader(mId);
	}

	unsigned int Shader::GetId() const
	{
		return mId;
	}

	void Shader::Compile()
	{
		glShaderSource(mId, 1, &mSource, nullptr); //TODO includes, etc
		glCompileShader(mId);
		//TODO compilations checks
	}
}