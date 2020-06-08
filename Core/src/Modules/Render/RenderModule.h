#ifndef EFFECTS_ENGINE_RENDER_MODULE
#define EFFECTS_ENGINE_RENDER_MODULE

#include "IModule.h"

namespace effectsEngine
{
	class ShaderProgram;
	class Mesh;
	class Texture;
	class Model;

	/**
	 * Class for the render module.
	 */
	class RenderModule : public IModule
	{
	public:
		/**
		 * Constructor.
		 */
		RenderModule();

		/**
		 * Destructor.
		 */
		virtual ~RenderModule();

		/**
		 * Initializes the module.
		 * \return True if everthing ok.
		 */
		bool Init() override;

		/**
		 * Updates the module.
		 * \param aDeltaTime Time since last update.
		 * \return True if everthing ok.
		 */
		bool Update(float aDeltaTime) override;

		/**
		 * Cleans the module.
		 */
		void Clean() override;

	private:
		ShaderProgram* mShaderProgram;
		Mesh* mMesh;
		Texture* mTexture;
		Model* mModel;

	};
}

#endif