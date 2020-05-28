#ifndef EFFECTS_ENGINE_MESH
#define EFFECTS_ENGINE_MESH

namespace effectsEngine
{
	/**
	 * Class for a mesh.
	 */
	class Mesh
	{
	public:
		/**
		 * Constructor.
		 */
		Mesh();
		
		/**
		 * Destructor.
		 */
		~Mesh();

		/**
		 * Initializes the mesh.
		 */
		void Init();

		/**
		 * Updates the mesh.
		 * \param aDeltaTime Time since last update.
		 */
		void Update(float aDeltaTime);

	private:
		unsigned int mVAO;		///< Index for the Vertex Array Object.
		unsigned int mVBO;		///< Index for the Vertex Buffer Object.
		unsigned int mEBO;		///< Index for the Element Buffer Object.
	};
}

#endif

