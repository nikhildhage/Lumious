#include "Indexbuffer.h"

namespace Lumious { namespace graphics {

	     // Constructor 
	     IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
		     : m_Count(count)

		{
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(GLuint), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			
		}


		 IndexBuffer::IndexBuffer(GLushort *data, GLsizei count)
			 : m_Count(count)

		 {
			 glGenBuffers(1, &m_BufferID);
			 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
			 glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(GLushort), data, GL_STATIC_DRAW);
			 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		 }

		 // Destructor
	    IndexBuffer ::~IndexBuffer()
	    {

			glDeleteBuffers(1, &m_BufferID);
	    }

		// Binds the IndexBuffer 
		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);

		}

		// Unbinds the IndexBuffer 
		void IndexBuffer::unbind() const
		{

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}




	}
}
