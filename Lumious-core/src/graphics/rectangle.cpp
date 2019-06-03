#include "rectangle.h"


namespace Lumious {namespace graphics 
{
		
	Rect::Rect(float x, float y, float width, float height, unsigned int color)
			:Renderable2D(maths ::vec3(x,y , (float)0) ,maths::vec2(width , height) ,color)
	{
		
	}
			
	Rect::~Rect()
	{

	}

}}