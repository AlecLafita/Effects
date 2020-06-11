#ifndef EFFECTS_ENGINE_SINGLETON
#define EFFECTS_ENGINE_SINGLETON

namespace effectsEngine
{
	/**
	 * Singleton base class.
	 * \tparam TClass Class to make singleton of.
	 */
	template<typename TClass>
	class Singleton
	{
	public:

		/**
		 * Obtains the singleton instance.
		 * \tparam TClass 
		 * \return Singleton instance of the class.
		 */
		static TClass& GetInstance()
		{
			static TClass mInstance;
			return mInstance;
		}

		/**
		 * Delete copy constructors to achieve singleton pattern.
		 */
		Singleton(Singleton const&) = delete;
		void operator=(Singleton const&) = delete;

	protected:
		/**
		 * Protected constructor to achieve singleton pattern.
		 */
		Singleton() {}
	};
}

#endif