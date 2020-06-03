#include "Shader.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

namespace effectsEngine
{
	Shader::Shader(eShaderType aShaderType, std::string&& aSourcePath) : 
		mId(0U),
		mSourcePath(aSourcePath)
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
		std::string shaderCode;
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			shaderFile.open(mSourcePath);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			shaderCode = shaderStream.str();

		}
		catch (std::ifstream::failure e)
		{
			//TODO throw exception
			std::cout <<  "Error couldn't read shader " << mSourcePath << " file: " << e.what() << std::endl;
			return false;
		}

		const char* shaderCodeLValue= shaderCode.c_str();
		glShaderSource(mId, 1, &shaderCodeLValue, nullptr); //TODO includes, etc
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