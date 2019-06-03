#include "buffer.h"

namespace Lumious { namespace graphics {

	// Constructor 
	Buffer::Buffer(GLfloat *data, GLsizei count, GLuint componentCount)
		: m_ComponentCount(componentCount)
	
	{

		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, count* sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//  Destructor 
	Buffer ::~Buffer()
	{
		glDeleteBuffers(1, &m_BufferID);

	}

	// Binds the Buffer
	 void Buffer::bind() const 
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);

	}


	 // Unbinds the Buffer
	 void Buffer::unbind() const
	 {

		 glBindBuffer(GL_ARRAY_BUFFER, 0);
	 }


}}
