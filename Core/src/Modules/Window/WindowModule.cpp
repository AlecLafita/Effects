#include "WindowModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{

	WindowModule::WindowModule()
	{

	}

	WindowModule::~WindowModule()
	{
	}

	bool WindowModule::Init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		mWindow = glfwCreateWindow(800, 600, "Effects", nullptr, nullptr);
		if (mWindow == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		glViewport(0, 0, 800, 600);

		glfwSetFramebufferSizeCallback(mWindow, WindowModule::Resize);

		return true;
	}

	bool WindowModule::Update(float aDeltaTime)
	{
		bool returnValue = false;
		if (!glfwWindowShouldClose(mWindow))
		{
			glfwSwapBuffers(mWindow);
			glfwPollEvents();

			returnValue = true;
		}

		return returnValue;
	}

	void WindowModule::Clean()
	{
		glfwTerminate();
	}

	void WindowModule::Resize(GLFWwindow* aWindow, int aWidth, int aHeight)
	{
		glViewport(0, 0, aWidth, aHeight);
	}

}
