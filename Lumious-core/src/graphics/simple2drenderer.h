#pragma once 

#include <deque>
#include "renderer2d.h"
#include"static_sprite.h"

namespace Lumious { namespace graphics {


	class Simple2DRenderer  : public Renderer2D
		{

		private :

			std::deque< StaticSprite* > m_RenderQueue;

		public :

			// methods to submit  renderabbles to the render and clear the render
			void submit(const Renderable2D*  renderable) override;
			void flush() override ;


		};



	}}