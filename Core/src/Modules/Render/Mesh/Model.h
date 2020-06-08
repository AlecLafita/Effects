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
		Model(const std::string& aPath);

		~Model();

		void Init();

		void Draw(ShaderProgram& aShaderProgram);

	private:
		std::vector<Mesh>			mMeshes;
	};
}

#endif
