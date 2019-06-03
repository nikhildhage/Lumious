#pragma once 

#include <iostream>

namespace Lumious { namespace maths {


	struct vec2
	{
		//public members
		float x, y;

		//constructors
		vec2()=default;
		vec2(const float &x , const float &y);

		//vector operation methods
		vec2& add(const vec2& other);
		vec2& subtract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		// vector  + - * /   operator overloading methods
		 friend vec2 operator +(vec2 left  , const vec2& right);
		 friend vec2 operator -(vec2 left , const vec2& right);
		 friend vec2 operator *(vec2 left , const vec2& right);
		 friend vec2 operator /(vec2 left , const vec2& right);

		 //vector += -= *= /= operator  overloading methods
		 vec2& operator +=(const vec2& other);
		 vec2& operator -=(const vec2& other);
		 vec2& operator *=(const vec2& other);
		 vec2& operator /=(const vec2& other);

		 //vector comparasion by overloading == and != operator methods 
		 bool operator ==(const vec2& other);
		 bool operator !=(const vec2& other);


		//creating output stream for vectors
		friend std::ostream& operator <<(std :: ostream& stream ,const vec2& vector );
	};


}}