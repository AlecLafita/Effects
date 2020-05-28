#include "RenderModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShaderCommon.h"
#include "ShaderProgram.h"
#include "Mesh.h"

namespace effectsEngine
{
	RenderModule::RenderModule() : 
		mShaderProgram(nullptr),
		mMesh(nullptr)
	{
	}

	RenderModule::~RenderModule()
	{
		delete mShaderProgram;
	}

	bool RenderModule::Init()
	{
		bool ReturnValue = true;

		const char* VSSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos, 1.0);\n"
			"}\0";
		Shader VS(eShaderType::Vertex, VSSource);
		ReturnValue &= VS.Compile();

		const char* FSSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(0.0f, 0.5f, 1.0f, 1.0f);\n"
			"}\0";
		Shader FS(eShaderType::Fragment, FSSource);
		ReturnValue &= FS.Compile();

		mShaderProgram = new ShaderProgram();
		mShaderProgram->AttachShader(VS);
		mShaderProgram->AttachShader(FS);
		ReturnValue &= mShaderProgram->Link();

		mMesh = new Mesh();
		mMesh->Init();

		return ReturnValue;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(mShaderProgram->GetId());
		mMesh->Update(aDeltaTime);

		return true;
	}

	void RenderModule::Clean()
	{

	}
}
