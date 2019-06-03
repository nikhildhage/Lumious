#pragma once 
#include <vector>
#include <GL/glew.h>
#include "../maths/maths.h"


namespace Lumious {  namespace graphics {

	
	    class Renderable2D;

	    class Renderer2D
	    {
			protected:
				std ::vector< maths ::mat4> m_TransformationStack;
				const maths::mat4* m_TransformationBack;
			protected :
				
				
				Renderer2D()
				{
					m_TransformationStack.push_back(maths::mat4::identity());
					m_TransformationBack=&m_TransformationStack.back();
				}

			public :
				
				//TransformationStack push method
				void push(const maths::mat4 matrix , bool overide =false) 
				{	
					if(overide)
						m_TransformationStack.push_back( matrix);
					else
					{
						m_TransformationStack.push_back(m_TransformationStack.back()* matrix);
						
					}
				}

				//TransformationStack push method
				void pop()
				{
					if (m_TransformationStack.size() > 1)
					{
						//m_TransformationBack = &m_TransformationStack.back();
						m_TransformationStack.pop_back();
						
					}
						
						
					m_TransformationBack = &m_TransformationStack.back();
				}

				// methods to submit renderabbles to the render and flush the render
				virtual void begin() {};
				virtual void submit( const Renderable2D* renderable )=0;
				virtual void end(){};
				virtual void flush()=0 ;

				const maths::mat4* getTransformationBack()
				{
					return m_TransformationBack;
				}


	     };


	
	}}