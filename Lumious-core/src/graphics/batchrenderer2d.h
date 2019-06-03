#pragma once 
#include <cstddef>
#include "renderable2d.h"

namespace Lumious { namespace graphics {

//MAx Sprites to 1 million 450000

// BatchRenderer2D defines 
#define RENDERER_MAX_SPRITES    60000
#define RENDERER_VERTEX_SIZE     sizeof(VertexData)
#define RENDERER_SPRITE_SIZE     RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE     RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES 
#define RENDERER_INDICES_SIZE    RENDERER_MAX_SPRITES * 6

#define  SHADER_VERTEX_INDEX   0
#define  SHADER_COLOR_INDEX    1



	class BatchRenderer2D : public Renderer2D
	{
		private:

			 GLuint m_VAO;      // Vertex Array object id 
			IndexBuffer* m_IBO;    // Index Buffer Object id 
			GLsizei m_IndexCount;   // count number of vertex Indices to draw 
			GLuint m_VBO;  // Vertex Buffer id
			VertexData* m_Buffer;  //pointer to VertexData Struct in Renderable2D
		
	    public:

			BatchRenderer2D();  
			~BatchRenderer2D();
		

			// methods to submit  renderabbles to the render and clear the render
			void begin() override;
			void submit(const Renderable2D*  renderable) override;
			void end() override;  
			void flush() override;
	};





}}


			




		