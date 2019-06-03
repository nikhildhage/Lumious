 #pragma once


#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"
#include "renderer2d.h"
#include "shader.h"

namespace Lumious { namespace graphics {
	struct VertexData
	{
		public :
			maths:: vec3 vertex;
			//maths::vec4 color;
			unsigned int color;
		
	};

	
	

	 class Renderable2D   
     {

		 protected :

			//Renderable2D properties
			 maths::vec3 m_position;
			 maths::vec2 m_Size;
			 unsigned int m_Color ;
			 
			
		protected :
			Renderable2D()
				:m_position(maths::vec3(0 ,0 ,0)), m_Size(maths ::vec2(0 ,0)) , m_Color(0x000000)
			{ 
			}
		 

		  public :

			
			   // constructor 
			   Renderable2D(maths::vec3 position, maths ::vec2 size, unsigned color )
				   :m_position(position), m_Size(size), m_Color(color)
			   {
				   
			   } 

			    virtual ~Renderable2D()
			   {
			   }

				virtual void submit(Renderer2D* renderer) const 
				{
					renderer->submit(this);
				}
					
				
				

			   // Gettter methods 
				void setColor(unsigned int color) { m_Color = color; };
				void setColor(maths::vec4 color)
				{
					int r = (int) color.x * 255;
					int g = (int) color.y * 255;
					int b = (int) color.z * 255;
					int a = (int)color.w * 255;
					m_Color = a << 24 | b << 16 | g << 8 | r;
					
				}
			
			   inline const maths::vec3& getPosition() const { return m_position; };
			   inline const maths ::vec2& getSize()  const {return  m_Size ; };
			   inline const unsigned int  getColor() const  { return m_Color; };
	
	 };


}}

