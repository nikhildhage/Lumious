#include "group.h"

namespace Lumious {namespace graphics {

	Group::Group(const maths::mat4& transform)
		: m_TransformationMatrix(transform)
	{
		
	}

	Group::~Group()
	{
		for (unsigned int  i = 0; i < m_Renderables.size(); i++)
			delete m_Renderables[i];
	}                                                                                                                                                                                                                                                   
	
	void Group::add(Renderable2D* renderable)
	{

		m_Renderables.push_back(renderable);

	}

	void Group::submit(Renderer2D * renderer) const
	{
		

		for(const Renderable2D * renderable : m_Renderables)                                                                                                                                                                                                    
			renderable->submit(renderer);
		
		renderer->pop();

	}








	
}}



