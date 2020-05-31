#include "RenderModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShaderCommon.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Image.h"

namespace effectsEngine
{
	//TODO auto relative path from project root
	const std::string RelativePath = "C:\\Users\\Alec\\Documents\\Effects\\";
	const std::string VSPath = "Core\\Resources\\default.vert";
	const std::string FSPath = "Core\\Resources\\default.frag";
	const std::string TexturePath = "Core\\Resources\\container.jpg";

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

		Shader VS(eShaderType::Vertex, RelativePath + VSPath);
		ReturnValue &= VS.Compile();
		
		Shader FS(eShaderType::Fragment, RelativePath + FSPath);
		ReturnValue &= FS.Compile();

		mShaderProgram = new ShaderProgram();
		mShaderProgram->AttachShader(VS);
		mShaderProgram->AttachShader(FS);
		ReturnValue &= mShaderProgram->Link();

		mMesh = new Mesh();
		mMesh->Init();

		Image TestImage;
		TestImage.Load(RelativePath + TexturePath);

		return ReturnValue;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		mShaderProgram->Activate(true);

		float greenValue = sin(glfwGetTime()) * 0.5f + 0.5f;
		mShaderProgram->SetVec4f("uniformColor", glm::vec4(0.0f, greenValue, 0.0f, 1.0f));

		mMesh->Update(aDeltaTime);

		mShaderProgram->Activate(false);

		//TODO check opengl errors

		return true;
	}

	void RenderModule::Clean()
	{

	}
}
