#ifndef EFFECTS_ENGINE_SHADER_PROGRAM
#define EFFECTS_ENGINE_SHADER_PROGRAM

#include <string>
#include <glm/glm.hpp>

namespace effectsEngine
{
	class Shader;

	/**
	 * Class for a shader program.
	 */
	class ShaderProgram
	{
	public:
		/**
		 * Constructor.
		 */
		ShaderProgram();

		/**
		 * Destructor.
		 */
		~ShaderProgram();

		/**
		* Gets the shader id.
		*/
		unsigned int GetId() const;

		/**
		 * Attachs a shader to the program.
		 * \param aShader Shader to attach.
		 */
		void AttachShader(const Shader& aShader);

		/**
		 * Links the shader program.
		 * \return True if everything ok.
		 */
		bool Link();

		/** Uniforms setting TODO uniform buffer object */

		void SetFloat(const std::string& aName, float aValue);

		void SetVec4f(const std::string& aName, const glm::vec4& aValue);

	private:
		unsigned int			mId;	///< Id of the shader program.
	};
}

#endif