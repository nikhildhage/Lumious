#pragma once 

#include <GL\glew.h>

namespace Lumious { namespace graphics {

		class IndexBuffer
		{

		private:

			GLuint m_BufferID;   // Buffer Id 

			GLuint m_Count;

		public:

			IndexBuffer(GLuint *data, GLsizei count);
			IndexBuffer(GLushort *data, GLsizei count);
			~IndexBuffer();
			void bind()  const;
			void unbind() const;
			inline GLuint getCount() const { return m_Count; }


		};

	}
}