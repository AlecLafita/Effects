#ifndef EFFECTS_ENGINE_PERSPECTIVE_CAMERA
#define EFFECTS_ENGINE_PERSPECTIVE_CAMERA

#include "Camera.h"

namespace effectsEngine
{
	/**
	 * Implementation of a perspective camera.
	 */
	class PerspectiveCamera : public Camera
	{
	public:
		/**
		 * Constructor.
		 */
		PerspectiveCamera(float aFOV = 45.0f);
		
		/**
		 * Constructor.
		 */
		PerspectiveCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar, float aFOV = 45.0f);

		/**
		 * Destructor.
		 */
		~PerspectiveCamera();

		/**
		 * Obtains the FOV value.
		 */
		const float GetFOV() const;

		/**
		 * Sets the FOV value.
		 */
		void SetFOV(float aFOV);

	protected:
		/**
		 * Recalculates the projection matrix from the camera attributes.
		 */
		virtual void RecalculateProjectionMatrix() override;

	private:
		float			mFOV;		///< Field Of View value.

	};
}

#endif