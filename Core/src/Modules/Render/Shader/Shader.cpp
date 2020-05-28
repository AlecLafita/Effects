#include "Shader.h"

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

	void Shader::Compile()
	{
		glShaderSource(mId, 1, &mSource, nullptr); //TODO includes, etc
		glCompileShader(mId);
		//TODO compilations checks
	}
}