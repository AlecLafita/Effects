#ifndef EFFECTS_ENGINE_RENDER_OPTIONS
#define EFFECTS_ENGINE_RENDER_OPTIONS

#include "Singleton.h"

namespace effectsEngine
{
	/**
	 * Singleton class which saves current render options and uses them to properly renderize.
	 */
	class RenderOptions : public Singleton<RenderOptions>
	{
	public:
		friend class Singleton<RenderOptions>;

		/**
		 * Activates the depth buffer.
		 * \param aActivate True for activate it, false otherwise.
		 */
		void ActivateDepthBuffer(bool aActivate);

		/**
		 * Activates the stencil buffer.
		 * \param aActivate True for activate it, false otherwise.
		 */
		void ActivateStencilBuffer(bool aActivate);

		/**
		 * Clears the rendered pixels as well as the buffers.
		 */
		void Clear();

	private:
		/**
		 * Private constructor to achieve singleton pattern.
		 */
		RenderOptions();

		bool mDepthBufferEnabled;		///< Flag to check if the depth buffer is enabled.
		bool mStencilBufferEnabled;		///< Flag to check if the depth buffer is enabled.
	};
}

#endif
