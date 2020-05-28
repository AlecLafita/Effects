#ifndef EFFECTS_ENGINE_SHADER
#define EFFECTS_ENGINE_SHADER

#include "ShaderCommon.h"

namespace effectsEngine
{
	/**
	 * Class for a shader.
	 */
	class Shader
	{
	public:
		/**
		 * Constructor.
		 * \param aShaderType Type of the shader being created.
		 * \param aSource Source of the shader to generate.
		 */
		Shader(eShaderType aShaderType, const char* aSource); //TODO change source with path

		/**
		 * Destructor.
		 */
		~Shader();

		/**  
		* Gets the shader id.
		*/
		unsigned int GetId() const;
		
		/**
		 * Compiles the shader.
		 * \return True if everything ok.
		 */
		bool Compile();

	private:
		unsigned int			mId;	///< Id of the shader.
		const char*			mSource;	///< Source of the shader.
	};
}

#endif