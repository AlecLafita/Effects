#ifndef EFFECTS_ENGINE_MODEL
#define EFFECTS_ENGINE_MODEL

#include <vector>
#include <string>
#include "Mesh.h"

namespace effectsEngine
{
	class ShaderProgram;

	/**
	 * Class for an object model.
	 */
	class Model
	{
	public:
		/**
		 * Constructor.
		 * \param aPath Path where the model file is located.
		 */
		Model(const std::string& aPath);

		/**
		 * Destructor.
		 * 
		 */
		~Model() = default;

		/**
		 * Initializes the model.
		 */
		void Init();

		/**
		 * Draws the model.
		 * \param aShaderProgram Shader to use to draw to model
		 */
		void Draw(ShaderProgram& aShaderProgram);

	private:
		std::vector<Mesh>			mMeshes;		///< Meshes the model is composed of.
	};
}

#endif
