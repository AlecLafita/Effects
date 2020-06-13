#include "RenderModule.h"
#include "RenderOptions.h"
#include "Shader.h"
#include "ShaderCommon.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include "Dirs.h"
#include "ModulesManager.h"
#include "CameraModule.h"
#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Model.h"

namespace effectsEngine
{
	const std::string VSPath = "default.vert";
	const std::string FSPath = "default.frag";
	const std::string TexturePath = "container.jpg";
	const std::string ModelPath = "Models/backpack/backpack.obj";

	RenderModule::RenderModule() : 
		mShaderProgram(nullptr),
		mMesh(nullptr),
		mModel(nullptr)
	{
	}

	RenderModule::~RenderModule()
	{
		delete mShaderProgram;
		delete mMesh;
		delete mModel;
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

		meshCommon::tVerticesContainer vertices = {
			meshCommon::sVertex{glm::vec3(0.5f,  0.5f, 0.0f),glm::vec3(), glm::vec2(1.0f, 1.0f)},
			meshCommon::sVertex{glm::vec3(0.5f, -0.5f, 0.0f),glm::vec3(), glm::vec2(1.0f, 0.0f)},
			meshCommon::sVertex{glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec3(), glm::vec2(0.0f, 0.0f)},
			meshCommon::sVertex{glm::vec3(-0.5f,  0.5f, 0.0f),glm::vec3(), glm::vec2(0.0f, 1.0f)},
		};
		meshCommon::tIndicesContainer indices = {
			0, 1, 3,
			1, 2, 3
		};
		auto texture = std::make_shared<Texture>(effectsEngine::utils::CORE_RESOURCES_PATH + TexturePath);
		meshCommon::tTexturesTypesContainer textures = { {texture, textureCommon::eTextureType::Diffuse} };
		mMesh = new Mesh(std::move(vertices), std::move(indices), std::move(textures));
		mMesh->Init();

		mModel = new Model(effectsEngine::utils::CORE_RESOURCES_PATH + ModelPath);
		mModel->Init();

		RenderOptions::GetInstance().ActivateDepthBuffer(true);

		return ReturnValue;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		RenderOptions::GetInstance().Clear();

		mShaderProgram->Activate(true);

		Camera& camera = ModulesManager::GetModule<CameraModule>(eModule::Camera).GetCamera();
		mShaderProgram->SetMat4f("uViewMatrix", camera.GetViewMatrix());
		mShaderProgram->SetMat4f("uProjectionMatrix", camera.GetProjectionMatrix());

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::rotate(modelMatrix, static_cast<float>(glfwGetTime())* glm::radians(10.0f), glm::vec3(0.f, 0.f, 1.0f));
		mShaderProgram->SetMat4f("uModelMatrix", modelMatrix);
		mMesh->Draw(*mShaderProgram);

		modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, -2.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, static_cast<float>(glfwGetTime())* glm::radians(180.0f), glm::vec3(0.f, 1.f, 0.0f));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.1f, 0.1f));
		mShaderProgram->SetMat4f("uModelMatrix", modelMatrix);
		mModel->Draw(*mShaderProgram); //TODO store model matrix at the model

		mShaderProgram->Activate(false);

		//TODO check opengl errors

		return true;
	}

	void RenderModule::Clean()
	{

	}
}
