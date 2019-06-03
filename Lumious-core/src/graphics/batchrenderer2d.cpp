#include "batchrenderer2d.h"

namespace Lumious {namespace graphics {
	
	                                                   
	// Constructor 
	BatchRenderer2D ::BatchRenderer2D()
	{
		
		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);

		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(0));
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// INdices Array
		GLuint* indices=new GLuint[RENDERER_INDICES_SIZE];

		int offset = 0; 

		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			 
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2; 
			
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			offset += 4;


		} //end of for loop 


		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		glBindVertexArray(0);

}

	//Destructor 
	BatchRenderer2D :: ~BatchRenderer2D()
	{
		
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
		
	}

	


	void BatchRenderer2D::begin()
	{
	

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	}


	void BatchRenderer2D ::submit(const Renderable2D*  renderable )
	{
		

		// Mapping the Bufffers 

		 const maths::vec3& position = renderable ->getPosition();
		 const maths :: vec2 size = renderable->getSize();
		 const unsigned int color = renderable->getColor();
		


		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		m_Buffer->vertex = *m_TransformationBack* position;
		m_Buffer->color = color;
		m_Buffer++;
		
		m_Buffer->vertex = *m_TransformationBack*maths ::vec3(position.x , position.y +size.y,  position.z);
		m_Buffer->color = color;
		m_Buffer++;

		m_Buffer->vertex = *m_TransformationBack * maths::vec3(position.x +size.x, position.y + size.y, position.z);
		m_Buffer->color = color;

		m_Buffer++;

		m_Buffer->vertex = *m_TransformationBack *  maths::vec3(position.x + size.x, position.y, position.z);
		m_Buffer->color = color;
		m_Buffer++;

		m_IndexCount += 6;

	}

	void BatchRenderer2D::end()
	{
		
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);


	}
	
	
	void BatchRenderer2D::flush()
	{

	

		// Bind  vertexArray and Index Buffer
		glBindVertexArray(m_VAO);
		m_IBO-> bind();

		// Draw the Sprites
		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

		// Unbind  vertexArray and INdex Bufferimd
		m_IBO->unbind();
		glBindVertexArray(0);
		      
		// Reset index coount to 0 after drawing sprites 
		m_IndexCount = 0;

	}


}}