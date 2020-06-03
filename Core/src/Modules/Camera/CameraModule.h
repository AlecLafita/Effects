#ifndef EFFECTS_ENGINE_CAMERA_MODULE
#define EFFECTS_ENGINE_CAMERA_MODULE

#include "IModule.h"
#include <memory>

namespace effectsEngine
{
	class Camera;

	/**
	 * Module for the camera control.
	 */
	class CameraModule : public IModule
	{
	public:
		/**
		 * Constructor.
		 */
		CameraModule();

		/**
		 * Destructor.
		 */
		virtual ~CameraModule();

		/**
		 * Initializes the module.
		 * \return True if everthing ok.
		 */
		virtual bool Init() override;

		/**
		 * Updates the module.
		 * \param aDeltaTime Time since last update.
		 * \return True if everthing ok.
		 */
		virtual bool Update(float aDeltaTime) override;

		/**
		 * Cleans the module.
		 */
		virtual void Clean() override;

		/**
		 * Returns the current camera.
		 * \return Reference to the current camera.
		 */
		Camera& GetCamera();

	private:
		std::unique_ptr<Camera>			mCamera;		///< Current camera instance.
	};
}

#endif