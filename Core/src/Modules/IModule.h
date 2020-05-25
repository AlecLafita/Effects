#ifndef EFFECTS_ENGINE_I_MODULE
#define EFFECTS_ENGINE_I_MODULE

namespace effectsEngine
{
	/**
	 * Interface for a module.
	 */
	class IModule
	{
	public:
		/**
		 * Constructor.
		 */
		IModule() {}

		/**
		 * Destructor.
		 */
		virtual ~IModule() {}

		/**
		 * Initializes the module.
		 * \return True if everthing ok.
		 */
		virtual bool Init() = 0;

		/**
		 * Updates the module.
		 * \param aDeltaTime Time since last update.
		 * \return True if everthing ok.
		 */
		virtual bool Update(float aDeltaTime) = 0;

		/**
		 * Cleans the module.
		 */
		virtual void Clean() = 0;
	};
}

#endif