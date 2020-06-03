#ifndef EFFECTS_ENGINE_CAMERA
#define EFFECTS_ENGINE_CAMERA

#include <glm/glm.hpp>

namespace effectsEngine
{
	/**
	 * Abstract class for a camera.
	 */
	class Camera
	{
	public:

		/**
		 * Constructor.
		 */
		Camera(const glm::vec3& aPosition = {0.f, 0.f, 0.f}, const glm::vec3& aUpDirection = { 0.f, 1.f, 0.f}, float aNear =  0.1f, float aFar = 50.f);

		/**
		 * Destructor.
		 */
		~Camera();

		/**
		 * Gets the camera position.
		 */
		const glm::vec3& GetPosition() const;

		/**
		 * Sets the camera position.
		 */
		void SetPosition(const glm::vec3& aPosition);

		/**
		 * Gets the view direction.
		 */
		const glm::vec3& GetViewDirection() const;
		
		/**
		 * Gets the right direction.
		 */
		const glm::vec3& GetRightDirection() const;

		/**
		 * Gets the up direction.
		 */
		const glm::vec3& GetUpDirection() const;

		/**
		 * Sets the up direction.
		 */
		void SetUpDirection(const glm::vec3& aUpDirection);

		/**
		 * Gets the near value.
		 */
		const float GetNear() const;

		/**
		 * Sets the near value.
		 */
		void SetNear(float aNear);

		/**
		 * Gets the far value.
		 */
		const float GetFar() const;

		/**
		 * Sets the far value.
		 */
		void SetFar(float aFar);

		/**
		 * Gets the yaw value.
		 */
		const float GetYaw() const;

		/**
		 * Set the yaw value.
		 */
		void SetYaw(float aYaw);

		/**
		 * Gets the pitch value.
		 */
		const float GetPitch() const;

		/**
		 * Sets the pitch value.
		 */
		void SetPitch(float aPitch);

		/**
		 * Sets the camera size.
		 */
		void SetSize(float aWidth, float aHeight);

		/**
		 * Gets the view matrix.
		 */
		const glm::mat4& GetViewMatrix() const;

		/**
		 * Gets the projection matrix.
		 */
		const glm::mat4& GetProjectionMatrix() const;

	protected:
		/**
		 * Recalculates the projection matrix from the camera attributes.
		 */
		virtual void RecalculateProjectionMatrix() = 0;

	private:
		/**
		 * Recalculates the view direction from the camera attributes.
		 */
		void RecalculateViewDirection();

		/**
		 * Recalculates the view matrix from the camera attributes.
		 */
		void RecalculateViewMatrix();

	protected:
		float			mNear;					///< Near value.
		float			mFar;					///< Far value.

		float			mWidth;					///< Width size.
		float			mHeight;				///< Height size.

		glm::mat4		mProjectionMatrix;		///< Projection matrix.

	private:
		glm::vec3		mPosition;				///< Position vector.

		glm::vec3		mViewDirection;			///< View direction vector.
		glm::vec3		mUpDirection;			///< Up direction vector.
		glm::vec3		mRightDirection;		///< Right direction vector

		float			mYaw;					///< Yaw value.
		float			mPitch;					///< Pitch value.

		glm::mat4		mViewMatrix;			///< View matrix
	};
}

#endif

