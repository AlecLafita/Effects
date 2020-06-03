#include "RenderModule.h"
#include "RenderOptions.h"
#include "Shader.h"
#include "ShaderCommon.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include "Dirs.h"

namespace effectsEngine
{
	const std::string VSPath = "default.vert";
	const std::string FSPath = "default.frag";
	const std::string TexturePath = "container.jpg";

	RenderModule::RenderModule() : 
		mShaderProgram(nullptr),
		mMesh(nullptr),
		mTexture(nullptr)
	{
	}

	RenderModule::~RenderModule()
	{
		delete mShaderProgram;
	}

	bool RenderModule::Init()
	{
		bool ReturnValue = true;

		Shader VS(eShaderType::Vertex, effectsEngine::utils::CORE_RESOURCES_PATH + VSPath);
		ReturnValue &= VS.Compile();
		
		Shader FS(eShaderType::Fragment, effectsEngine::utils::CORE_RESOURCES_PATH + FSPath);
		ReturnValue &= FS.Compile();

		mShaderProgram = new ShaderProgram();
		mShaderProgram->AttachShader(VS);
		mShaderProgram->AttachShader(FS);
		ReturnValue &= mShaderProgram->Link();

		mMesh = new Mesh();
		mMesh->Init();

		mTexture = new Texture(effectsEngine::utils::CORE_RESOURCES_PATH + TexturePath);
		mShaderProgram->Activate(true);
		mShaderProgram->SetInt("uniformTexture1", 0U);
		mShaderProgram->Activate(false);

		RenderOptions::GetInstance().ActivateDepthBuffer(false);

		return ReturnValue;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		RenderOptions::GetInstance().Clear();

		mTexture->Use();

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
