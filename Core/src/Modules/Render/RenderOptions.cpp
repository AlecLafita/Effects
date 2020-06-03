#include "RenderOptions.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{
	RenderOptions::RenderOptions() :
		mDepthBufferEnabled(false),
		mStencilBufferEnabled(false)
	{
	}

	RenderOptions& RenderOptions::GetInstance()
	{
		static RenderOptions	mInstance;
		return mInstance;
	}

	void RenderOptions::ActivateDepthBuffer(bool aActivate)
	{
		if (aActivate)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
		mDepthBufferEnabled = aActivate;
		//TODO op, mask, etc
	}

	void RenderOptions::ActivateStencilBuffer(bool aActivate)
	{
		if (aActivate)
		{
			glEnable(GL_STENCIL_TEST);
		}
		else
		{
			glDisable(GL_STENCIL_TEST);
		}
		mStencilBufferEnabled  = aActivate;
		//TODO op, mask, etc
	}

	void RenderOptions::Clear()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | 
				(mDepthBufferEnabled ? GL_DEPTH_BUFFER_BIT : 0U) |
				(mStencilBufferEnabled ? GL_STENCIL_BUFFER_BIT: 0U)
		);
	}
}