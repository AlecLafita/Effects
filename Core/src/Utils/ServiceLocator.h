#ifndef EFFECTS_ENGINE_SERVICE_LOCATOR
#define EFFECTS_ENGINE_SERVICE_LOCATOR

#include <memory>

namespace effectsEngine
{
	/**
	 * Class for a service locator.
	 * \tparam Type of the service to locate.
	 */
	template<typename TService>
	class ServiceLocator
	{
	public:

		~ServiceLocator() = default;

		/**
		 * Gets the service. asserts if no service has been provided.
		 * \return Service this class is responsible to locate.
		 */
		static TService& GetService()
		{
			assert(mService != nullptr);
			return *mService;
		}

		/**
		 * Provides the service.
		 * \param aService Service which will be located.
		 */
		static void ProvideService(TService* aService)
		{
			mService = std::unique_ptr<TService>(aService);
		}

	private:
		inline static std::unique_ptr<TService> mService = nullptr;		///< Service this class is responsible to locate.
	};
}

#endif