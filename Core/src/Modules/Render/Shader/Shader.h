#ifndef EFFECTS_ENGINE_SHADER
#define EFFECTS_ENGINE_SHADER

#include "ShaderCommon.h"
#include <string>

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
		 * \param aSourcePath Path to the source of the shader to generate.
		 */
		Shader(eShaderType aShaderType, const std::string&& aSourcePath);

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
		unsigned int			mId;			///< Id of the shader.
		const std::string		mSourcePath;	///< Path to the source of the shader.
	};
}

#endif