#include "WindowModule.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{

	WindowModule::WindowModule() :
		mWindowCallbacksManager()
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
		GLFWwindow* currentWindow = glfwCreateWindow(800, 600, "Effects", nullptr, nullptr);
		if (currentWindow == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(currentWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		glViewport(0, 0, 800, 600);

		glfwSetWindowUserPointer(currentWindow, &mWindowCallbacksManager);

		auto ResizeCallback = [](GLFWwindow* laWindow, int laWidth, int laHeight)
		{
			static_cast<WindowCallbacksManager*>(glfwGetWindowUserPointer(laWindow))->Resize(laWidth, laHeight);
		};
		glfwSetFramebufferSizeCallback(currentWindow, ResizeCallback);

		return true;
	}

	bool WindowModule::Update(float aDeltaTime)
	{
		bool returnValue = false;

		GLFWwindow* currentWindow = glfwGetCurrentContext();
		if (!glfwWindowShouldClose(currentWindow))
		{
			glfwSwapBuffers(currentWindow);
			glfwPollEvents();

			returnValue = true;
		}

		return returnValue;
	}

	void WindowModule::Clean()
	{
		glfwTerminate();
	}
}
