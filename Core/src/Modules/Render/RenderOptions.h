#ifndef EFFECTS_ENGINE_RENDER_OPTIONS
#define EFFECTS_ENGINE_RENDER_OPTIONS

namespace effectsEngine
{
	/**
	 * Singleton class which saves current render options and uses them to properly renderize.
	 */
	class RenderOptions
	{
	public:

		/**
		 * Obtains the singleon instance.
		 * \return Singleton instance of the class.
		 */
		static RenderOptions& GetInstance();
		
		/**
		 * Delete copy constructors.
		 */
		RenderOptions(RenderOptions const&) = delete;
		void operator=(RenderOptions const&) = delete;

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
		RenderOptions();				//!< Private constructor to have it as a singleton.

		bool mDepthBufferEnabled;		///< Flag to check if the depth buffer is enabled.
		bool mStencilBufferEnabled;		///< Flag to check if the depth buffer is enabled.
	};
}

#endif