#include "vec2.h"

namespace Lumious { namespace maths {

	//default vector constructor 


	//non-default vector constructor 
	vec2::vec2(const float &x, const float &y)
		:x(x), y(y)
	{
		

	}


	
	// add two vectors 
	vec2& vec2 ::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}


	//subtract two vectors
	vec2& vec2::subtract(const vec2& other)
	{

		x -= other.x;
		y -= other.y;

		return *this;
	}


	//multiply two vectors
	vec2& vec2::multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}


	//divide two vectors 
	vec2& vec2::divide(const vec2& other)
	{

		x /= other.x;
		y /= other.y;

		return *this;

	}


	// adds two vectors with + operator 
	vec2 operator +(vec2 left, const vec2& right)
	{
		return left.add(right);
	}


	//subtracrs two vectors with - operator
	vec2 operator -(vec2 left, const vec2& right)
	{
		return left.subtract(right);
	}


	//multiplies two vectors with * operator
	vec2 operator *(vec2 left, const vec2& right)
	{
		return left.multiply(right);
	}


	//divides two vectors with / operator
	vec2 operator /(vec2 left, const vec2& right)
	{
		return left.divide(right);
	}


	// adds two vectors with += operator 
	vec2& vec2 :: operator +=(const vec2& other)
	{
		return add(other);

	}

	//subtracrs two vectors with -= operator
	vec2& vec2 ::operator -=(const vec2& other)
	{
		return subtract(other);

	}

	//multiplies two vectors with *= operator
	vec2& vec2 ::operator *=(const vec2& other)
	{
		return multiply(other);

	}

	//divides two vectors with /= operator
	vec2& vec2 ::operator/=(const vec2& other)
	{
		return divide(other);

	}

	//vector comparasion by overloading == operator method 
	bool vec2 ::operator==(const vec2& other)
	{
		 return x == other.x && y == other.y;
	}

	//vector comparasion by overloading == operator method 
	bool vec2 ::operator !=(const vec2& other)
	{
		return !(*this == other);
	}



	//output stream 
	std::ostream& operator <<(std::ostream& stream, const vec2& vector)
	{

		stream << "vec2 : (" << vector.x <<"," << vector.y  <<")";
		return stream;
	}


}}