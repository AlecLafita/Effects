#include "RenderModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShaderCommon.h"
#include "ShaderProgram.h"

namespace effectsEngine
{

	RenderModule::RenderModule() : 
		mShaderProgram(nullptr)
	{
	}

	RenderModule::~RenderModule()
	{
		delete mShaderProgram;
	}

	bool RenderModule::Init()
	{
		//TODO organize this

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		const char* VSSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
		Shader VS(eShaderType::Vertex, VSSource);
		VS.Compile();

		const char* FSSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\0";
		Shader FS(eShaderType::Fragment, FSSource);
		FS.Compile();

		mShaderProgram = new ShaderProgram();
		mShaderProgram->AttachShader(VS);
		mShaderProgram->AttachShader(FS);
		mShaderProgram->Link();

		glUseProgram(mShaderProgram->GetId());



		return true;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		return true;
	}

	void RenderModule::Clean()
	{

	}
}
