#pragma once 

#include <iostream>

namespace Lumious { namespace maths {


	struct vec4
	{
		//public members
		float x, y , z, w;

		//constructors
		
		vec4()=default;
		vec4(const float &x, const float &y, const float &z, const float &w) ;

		//vector operation methods
		vec4& add(const vec4& other);
		vec4& subtract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		// vector  + - * /   operator overloading methods
		 friend vec4 operator +(vec4 left  , const vec4& right);
		 friend vec4 operator -(vec4 left , const vec4& right);
		 friend vec4 operator *(vec4 left , const vec4& right);
		 friend vec4 operator /(vec4 left , const vec4& right);

		 //vector += -= *= /= operator  overloading methods
		 vec4& operator +=(const vec4& other);
		 vec4& operator -=(const vec4& other);
		 vec4& operator *=(const vec4& other);
		 vec4& operator /=(const vec4& other);

		 //vector comparasion by overloading == and != operator methods 
		 bool operator ==(const vec4& other);
		 bool operator !=(const vec4& other);


		//creating output stream for vectors
		friend std::ostream& operator <<(std :: ostream& stream ,const vec4& vector );
	};


}}