#include "layer.h"


namespace Lumious { namespace graphics {
	 
	Layer::Layer(Renderer2D* renderer, Shader* shader, maths ::mat4 projectionMatrix) 
	 : m_Renderer(renderer) , m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
	{
		shader->enable();
		shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
		
		
		
	}
	
	Layer ::~Layer()
	{
		std::cout <<"Deleting shader , renderer , and std : vector< Renderable2d *>"  << std::endl;
	
		delete m_Shader;
		delete m_Renderer;
		
		for (unsigned int i = 0; i < m_Renderables.size(); i++)
			delete m_Renderables[i];


	}


	 void Layer ::add(Renderable2D* renderable)
	 {
		 m_Renderables.push_back(renderable);
	 }

	 

	
	 void Layer::render()
	 {
		 //Start Renderering
		

		 m_Shader->enable();
		 m_Renderer->begin();
		
		 //m_Renderer->push(maths ::mat4 ::translation( maths::vec3( 3 ,3, 0)));
		 for (const Renderable2D* renderable :m_Renderables)
		 {
			 
			 renderable->submit(m_Renderer);
			 //std::cout << "Rendering new Rect" << std::endl;
		 }
			

		 
		 m_Renderer->end();
		 m_Renderer->flush();
		
	 }

	  Renderer2D* Layer::getRenderer()
	 {
		  return m_Renderer;
	 }
}}
