#ifndef EFFECTS_ENGINE_I_MODEL_LOADER
#define EFFECTS_ENGINE_I_MODEL_LOADER

#include <string>
#include <vector>

namespace effectsEngine
{
	class Mesh;

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
		 * Loads a model from a file. Textures are also loaded.
		 * \param aPath Path where the model is located.
		 * \param aMesh Container of model's meshes where the result meshes will be stored.
		 */
		virtual void ReadModel(const std::string& aPath, std::vector<Mesh>& aMesh) = 0;
	};
};

#endif
