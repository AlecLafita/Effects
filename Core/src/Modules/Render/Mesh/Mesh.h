#ifndef EFFECTS_ENGINE_MESH
#define EFFECTS_ENGINE_MESH

#include <vector>
#include <string>
#include <memory>
#include <glm/glm.hpp>
#include "TextureCommon.h"

namespace effectsEngine
{
	class ShaderProgram;
	class Texture;

	/**
	 * Class for a mesh.
	 */
	class Mesh
	{
	public:
		/**
		 * Struct defined for the vertex properties.
		 */
		struct sVertex 
		{
			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TexCoords;
		};

		struct sTexture
		{
			std::shared_ptr<Texture> Texture;
			std::string UniformName;
		};

		typedef std::vector<sVertex>					tVerticesContainer;		///< Type defined for a container of vertices.
		typedef std::vector<unsigned int>				tIndicesContainer;		///< Type defined for a container of vertices indices.
		typedef std::vector<std::pair<std::shared_ptr<Texture>, textureCommon::eTextureType>>	tTexturesContainer;		///< Type defined for a container of sTextures.
		typedef std::vector<sTexture>					tsTexturesContainer;	///< Type defined for a container of sTextures.

		/**
		 * Constructor.
		 */
		Mesh(tVerticesContainer&& aVertices, tIndicesContainer&& aIndices, tTexturesContainer&& aTextures);
		
		/**
		 * Destructor.
		 */
		~Mesh();

		/**
		 * Initializes the mesh.
		 */
		void Init();

		/**
		 * Draws the mesh.
		 * \param aShaderProgram Shader program to use to draw the mesh.
		 */
		void Draw(ShaderProgram& aShaderProgram);

	private:
		unsigned int mVAO;		///< Index for the Vertex Array Object.
		unsigned int mVBO;		///< Index for the Vertex Buffer Object.
		unsigned int mEBO;		///< Index for the Element Buffer Object.

		tVerticesContainer		mVertices;		///< Vertices of the mesh.
		tIndicesContainer		mIndices;		///< Indices for the triangles vertices of the mesh.
		tsTexturesContainer		mTextures;		///< Texture of the mesh.

	};
}

#endif

