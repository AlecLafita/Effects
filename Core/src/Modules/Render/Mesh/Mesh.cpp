#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <map>
#include "Texture.h"

namespace effectsEngine
{
	Mesh::Mesh(tVerticesContainer&& aVertices, tIndicesContainer&& aIndices, tTexturesContainer&& aTextures) :
		mVAO(0U),
		mVBO(0U),
		mEBO(0U),
		mVertices(aVertices),
		mIndices(aIndices),
		mTextures()
	{
		mTextures.reserve(aTextures.size());
		std::map<textureCommon::eTextureType, uint8_t> textureTypesCounter;
		for (auto CurrentTexture : aTextures)
		{
			auto textureTypesCounterIterator = textureTypesCounter.find(CurrentTexture.second);
			if (textureTypesCounterIterator == textureTypesCounter.end())
			{
				textureTypesCounterIterator = textureTypesCounter.emplace(CurrentTexture.second, 0U).first;
			}
			else
			{
				textureTypesCounterIterator->second++;
			}
			mTextures.push_back({CurrentTexture.first, textureCommon::GetUniformNameFromType(CurrentTexture.second) + std::to_string(textureTypesCounterIterator->second) });
		}
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1U, &mVAO);
		glDeleteBuffers(1U, &mVBO);
		glDeleteBuffers(1U, &mEBO);
	}

	void Mesh::Init()
	{
		glGenVertexArrays(1U, &mVAO);
		glGenBuffers(1U, &mVBO);
		glGenBuffers(1U, &mEBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sVertex) * mVertices.size(), &mVertices.at(0), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mIndices.size(), &mIndices.at(0), GL_STATIC_DRAW);

		//Position
		glEnableVertexAttribArray(0U);
		glVertexAttribPointer(0U, 3U, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)0U);

		//Normal
		glEnableVertexAttribArray(1U);
		glVertexAttribPointer(1U, 3U, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)(offsetof(sVertex, Normal)));
		
		//TexCoords
		glEnableVertexAttribArray(2U);
		glVertexAttribPointer(2U, 2U, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)(offsetof(sVertex, TexCoords)));

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0U);
	}

	void Mesh::Draw(ShaderProgram& aShaderProgram)
	{
		for (size_t currentTextureIndex = 0U; currentTextureIndex < mTextures.size(); ++currentTextureIndex)
		{
			mTextures.at(currentTextureIndex).Texture->Use(aShaderProgram, mTextures.at(currentTextureIndex).UniformName, currentTextureIndex);
		}

		glBindVertexArray(mVAO);
		glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, 0U);
		glBindVertexArray(0U);
	}
}