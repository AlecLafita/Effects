#ifndef EFFECTS_ENGINE_ORTHOGONAL_CAMERA
#define EFFECTS_ENGINE_ORTHOGONAL_CAMERA

#include "Camera.h"

namespace effectsEngine
{
	/**
	 * Implementation of an orthogonal camera.
	 */
	class OrthogonalCamera : public Camera
	{
	public:

		/**
		 * Constructor.
		 */
		OrthogonalCamera();

		/**
		 * Constructor.
		 */
		OrthogonalCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar);

		/**
		 * Destructor.
		 */
		~OrthogonalCamera();

		/**
		 * Obtains the center of the camera.
		 */
		const glm::vec2& GetCenter() const;

		/**
		 * Sets the center of the camera.
		 */
		void SetCenter(glm::vec2 aCenter);

	protected:
		/**
		 * Recalculates the projection matrix from the camera attributes.
		 */
		virtual void RecalculateProjectionMatrix() override;

	private:
		glm::vec2			mCenter;		///< Center vector.

	};
}

#endif