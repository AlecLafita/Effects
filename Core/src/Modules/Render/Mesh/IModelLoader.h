#ifndef EFFECTS_ENGINE_I_MODEL_LOADER
#define EFFECTS_ENGINE_I_MODEL_LOADER

#include <string>
#include <vector>
#include "Mesh.h"

namespace effectsEngine
{
	/**
	 * Interface to load a model from file. All subclases should be a singleton type.
	 */
	class IModelLoader
	{
	public:
		/**
		 * Constructor
		 */
		IModelLoader() {}

		/**
		 * Destructor.
		 */
		virtual ~IModelLoader() {}

		/**
		 * Loads a model from a file.
		 * \param aPath Path where the model is located.
		 * \return Container of model's meshes. Textures are also loaded.
		 */
		virtual const std::vector<Mesh> ReadModel(const std::string& aPath) = 0;
	};
};

#endif
