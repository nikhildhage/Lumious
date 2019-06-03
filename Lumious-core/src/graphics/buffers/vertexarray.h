#pragma once 

#include <vector>
#include <GL\glew.h>
#include "buffer.h"

namespace Lumious {namespace graphics {
	
	class VertexArray
	{

	private :

		GLuint m_ArrayID;   // vertex array ID
		 
		std::vector<Buffer*> m_Buffers;  // vector of buffer pointers

	public : 

		VertexArray();
		~VertexArray();


		void addBuffer(Buffer* buffer , GLuint index );
		void bind() const;
		void unbind() const;

	};

	
	}}
