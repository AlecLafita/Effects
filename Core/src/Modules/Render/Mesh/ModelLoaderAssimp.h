#ifndef EFFECTS_ENGINE_MODEL_LOADER_ASSIMP
#define EFFECTS_ENGINE_MODEL_LOADER_ASSIMP

#include "IModelLoader.h"

namespace effectsEngine
{
	/**
	 * Implementation for a model loader ussing assimp library.
	 */
	class ModelLoaderAssimp : public IModelLoader
	{
	public:
		ModelLoaderAssimp();

		virtual ~ModelLoaderAssimp();
	private:

	};
}

#endif
