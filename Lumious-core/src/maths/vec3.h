#pragma once 

#include <iostream>

namespace Lumious { namespace maths {


	struct vec3
	{
		//public members
		float x, y , z;

		//constructors
		vec3()=default;
		vec3(const int &x, const int &y, const int &z);
		vec3(const float &x , const float &y , const float&z);
		vec3(const double&x, const double&y, const double&z);
		//vector operation methods
		vec3& add(const vec3& other);
		vec3& subtract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);

		// vector  + - * /   operator overloading methods
		 friend vec3 operator +(vec3 left  , const vec3& right);
		 friend vec3 operator -(vec3 left , const vec3& right);
		 friend vec3 operator *(vec3 left , const vec3& right);
		 friend vec3 operator /(vec3 left , const vec3& right);

		 //vector += -= *= /= operator  overloading methods
		 vec3& operator +=(const vec3& other);
		 vec3& operator -=(const vec3& other);
		 vec3& operator *=(const vec3& other);
		 vec3& operator /=(const vec3& other);

		 //vector comparasion by overloading == and != operator methods 
		 bool operator ==(const vec3& other);
		 bool operator !=(const vec3& other);


		//creating output stream for vectors
		friend std::ostream& operator <<(std :: ostream& stream ,const vec3& vector );
	};


}}