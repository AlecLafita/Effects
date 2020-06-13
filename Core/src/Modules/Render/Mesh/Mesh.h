#ifndef EFFECTS_ENGINE_MESH
#define EFFECTS_ENGINE_MESH

#include "MeshCommon.h"

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
		 * Constructor.
		 */
		Mesh(meshCommon::tVerticesContainer&& aVertices, meshCommon::tIndicesContainer&& aIndices, meshCommon::tTexturesTypesContainer&& aTextures);
		
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

		/**
		 * Struct defined for a texture along its uniform name used by a mesh.
		 */
		struct sTextureUniform
		{
			std::shared_ptr<Texture> Texture;
			std::string UniformName;
		};
		typedef std::vector<sTextureUniform>			tTexturesUniformContainer;	///< Type defined for a container of sTextures.

		unsigned int mVAO;		///< Index for the Vertex Array Object.
		unsigned int mVBO;		///< Index for the Vertex Buffer Object.
		unsigned int mEBO;		///< Index for the Element Buffer Object.

		meshCommon::tVerticesContainer			mVertices;		///< Vertices of the mesh.
		meshCommon::tIndicesContainer			mIndices;		///< Indices for the triangles vertices of the mesh.
		tTexturesUniformContainer				mTextures;		///< Textures of the mesh.

	};
}

#endif

