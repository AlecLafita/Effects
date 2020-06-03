#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace effectsEngine
{
	Camera::Camera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar) :
		mPosition(aPosition),
		mViewDirection(),
		mUpDirection(aUpDirection),
		mRightDirection(),
		mNear(aNear),
		mFar(aFar),
		mYaw(-90.f),
		mPitch(0.f),
		mWidth(),
		mHeight()
	{
		RecalculateViewDirection();
	}
	
	Camera::~Camera()
	{

	}

	const glm::vec3& Camera::GetPosition() const
	{
		return mPosition;
	}

	void Camera::SetPosition(const glm::vec3& aPosition)
	{
		mPosition = aPosition;
		RecalculateViewMatrix();
	}

	const glm::vec3& Camera::GetViewDirection() const
	{
		return mViewDirection;
	}
	
	const glm::vec3& Camera::GetRightDirection() const
	{
		return mRightDirection;
	}

	const glm::vec3& Camera::GetUpDirection() const
	{
		return mUpDirection;
	}

	void Camera::SetUpDirection(const glm::vec3& aUpDirection)
	{
		mUpDirection = aUpDirection;
		RecalculateViewMatrix();
	}

	const float Camera::GetNear() const
	{
		return mNear;
	}

	void Camera::SetNear(float aNear)
	{
		mNear = aNear;
		RecalculateProjectionMatrix();
	}

	const float Camera::GetFar() const
	{
		return mFar;
	}

	void Camera::SetFar(float aFar)
	{
		mFar = aFar;
		RecalculateProjectionMatrix();
	}

	const float Camera::GetYaw() const
	{
		return mYaw;
	}

	void Camera::SetYaw(float aYaw)
	{
		mYaw = aYaw;
		RecalculateViewDirection();
	}

	const float Camera::GetPitch() const
	{
		return mPitch;
	}

	void Camera::SetPitch(float aPitch)
	{
		mPitch = aPitch;
		RecalculateViewDirection();
	}

	void Camera::SetSize(float aWidth, float aHeight)
	{
		if (aWidth != 0 || aHeight != 0)
		{
			mWidth = aWidth;
			mHeight = aHeight;
			RecalculateProjectionMatrix();
		}
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		return mViewMatrix;
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		return mProjectionMatrix;
	}

	void Camera::RecalculateViewDirection()
	{
		mViewDirection.x = cos(glm::radians(mPitch)) * cos(glm::radians(mYaw));
		mViewDirection.y = sin(glm::radians(mPitch));
		mViewDirection.z = cos(glm::radians(mPitch)) * sin(glm::radians(mYaw));
		mViewDirection = glm::normalize(mViewDirection);

		mRightDirection = glm::normalize(glm::cross(mViewDirection, mUpDirection));

		RecalculateViewMatrix();
	}

	void Camera::RecalculateViewMatrix()
	{
		mViewMatrix = glm::lookAt(mPosition, mPosition + mViewDirection, mUpDirection);
	}

}