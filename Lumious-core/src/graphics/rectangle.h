#pragma once

#include "renderable2d.h"

namespace Lumious { namespace graphics {
	
	class Rect : public Renderable2D
	{

		private:
			maths::vec3 position;

		public:
			Rect(float x, float y, float width, float height, unsigned int color);
			~Rect();
			


			 

	};


}}