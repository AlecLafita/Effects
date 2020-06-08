#ifndef EFFECTS_ENGINE_I_MODEL_LOADER
#define EFFECTS_ENGINE_I_MODEL_LOADER

#include <vector>
#include "Mesh.h"

namespace effectsEngine
{
	/**
	 * Interface to load a model from file.
	 */
	class IModelLoader
	{
	public:
		/**
		 * Constructor.
		 */
		IModelLoader() : mMeshes() {}

		/**
		 * Destructor.
		 */
		virtual ~IModelLoader() {}

		const std::vector<Mesh>& GetMeshes() const { return mMeshes;}

	protected:
		std::vector<Mesh>	mMeshes;	///< Meshed loaded.	

	};
};

#endif
