#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace effectsEngine
{
	Mesh::Mesh() : 
		mVAO(0U),
		mVBO(0U),
		mEBO(0U)
	{
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1U, &mVAO);
		glDeleteBuffers(1U, &mVBO);
		glDeleteBuffers(1U, &mEBO);
	}

	void Mesh::Init()
	{
		//TODO organize vertex properties
		float vertices[] = {
			 0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f, // top right
			 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,// bottom right
			-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f, // bottom left
			-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 1.0f// top left 
		};
		unsigned int indices[] = {
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};

		glGenVertexArrays(1U, &mVAO);
		glGenBuffers(1U, &mVBO);
		glGenBuffers(1U, &mEBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0U);
		glVertexAttribPointer(0U, 3U, GL_FLOAT, GL_FALSE, 6U * sizeof(float), (void*)0U);

		glEnableVertexAttribArray(1U);
		glVertexAttribPointer(1U, 3U, GL_FLOAT, GL_FALSE, 6U * sizeof(float), (void*)(3U * sizeof(float)));

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0U);
		
	}

	void Mesh::Update(float aDeltaTime)
	{
		glBindVertexArray(mVAO);
		glDrawElements(GL_TRIANGLES, 6U, GL_UNSIGNED_INT, 0U);
		glBindVertexArray(0U);
	}
}