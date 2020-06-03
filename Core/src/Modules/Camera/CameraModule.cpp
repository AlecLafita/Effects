#include "CameraModule.h"
#include "PerspectiveCamera.h"
#include "OrthogonalCamera.h"

namespace effectsEngine
{
	CameraModule::CameraModule() :
		mCamera(nullptr)
	{
	}

	CameraModule::~CameraModule()
	{
	}

	bool CameraModule::Init()
	{
		mCamera = std::make_unique<PerspectiveCamera>();
		mCamera->SetSize(800, 600); //TODO get from windows module
		mCamera->SetPosition({ 0.f, 0.f, 6.f });
		return true;
	}

	bool CameraModule::Update(float aDeltaTime)
	{
		return true;
	}

	void CameraModule::Clean()
	{

	}
	Camera& CameraModule::GetCamera()
	{
		return *mCamera.get();
	}

	//TODO key, mouse callbacks to move the camera
}