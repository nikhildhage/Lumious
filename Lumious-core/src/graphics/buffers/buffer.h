  #pragma once 

#include <GL\glew.h>

namespace Lumious { namespace graphics {

	class Buffer
	{

	private :

		GLuint m_BufferID;   // Buffer Id 

		GLuint m_ComponentCount; // count for the number of elements in a Buffer  

	public :

		Buffer(GLfloat *data, GLsizei count, GLuint componentCount);
		~Buffer();
		void bind()  const;
		void unbind() const ;
		inline GLuint getComponentCount() const { return m_ComponentCount; }


	};

}}
