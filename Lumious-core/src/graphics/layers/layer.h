#pragma once

#include "../renderable2d.h"


namespace Lumious { namespace graphics {

	class Layer {

		protected:
			Renderer2D* m_Renderer;   // pointer to Renderer2D object     
			std::vector<Renderable2D *> m_Renderables;  // vector of Renderable2D Objects
			Shader* m_Shader;  // pointer to Shader
			maths::mat4 m_ProjectionMatrix;     // Projection Matrix
			//std::vector<maths::mat4> transformatiosn;
			Layer(Renderer2D * renderer, Shader * shader , maths :: mat4 projectionMatrix); // constructor 

		public :
			
			virtual ~Layer();
			virtual void add(Renderable2D *renderable);
			virtual Renderer2D* getRenderer();
			virtual void render();
			
			
	};

}}