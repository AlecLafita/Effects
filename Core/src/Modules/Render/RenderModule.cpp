#include "RenderModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{

	RenderModule::RenderModule()
	{
	}

	RenderModule::~RenderModule()
	{
	}

	bool RenderModule::Init()
	{
		return true;
	}

	bool RenderModule::Update(float aDeltaTime)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		return true;
	}

	void RenderModule::Clean()
	{

	}
}
