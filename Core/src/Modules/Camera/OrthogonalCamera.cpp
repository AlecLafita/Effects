#include "OrthogonalCamera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace effectsEngine
{
	OrthogonalCamera::OrthogonalCamera() :
		Camera(),
		mCenter()
	{
	}
	
	OrthogonalCamera::OrthogonalCamera(const glm::vec3& aPosition, const glm::vec3& aUpDirection, float aNear, float aFar) :
		Camera(aPosition, aUpDirection, aNear, aFar),
		mCenter()
	{
	}

	OrthogonalCamera::~OrthogonalCamera()
	{

	}

	const glm::vec2& OrthogonalCamera::GetCenter() const
	{
		return mCenter;
	}

	void OrthogonalCamera::SetCenter(glm::vec2 aCenter)
	{
		mCenter = aCenter;
		RecalculateProjectionMatrix();
	}

	void OrthogonalCamera::RecalculateProjectionMatrix()
	{
		float Left = mCenter.x - mWidth / 2.0f;
		float Right= mCenter.x + mWidth / 2.0f;
		float Bottom = mCenter.y - mHeight / 2.0f;
		float Top = mCenter.y - mHeight / 2.0f;
		mProjectionMatrix = glm::ortho(Left, Right, Bottom, Top, mNear, mFar);
	}
}