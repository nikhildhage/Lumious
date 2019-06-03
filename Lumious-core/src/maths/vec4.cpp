#include "vec4.h"

namespace Lumious { namespace maths {

	

	//non-default vector constructor 
	vec4::vec4(const float &x, const float &y , const float& z , const float& w)
		: x(x), y(y), z(z), w(w)
	{
	}


	
	// add two vectors 
	vec4& vec4 ::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}


	//subtract two vectors
	vec4& vec4::subtract(const vec4& other)
	{

		x -= other.x;
		y -= other.y;
	    z -= other.z;
	    w -= other.w;


		return *this;
	}


	//multiply two vectors
	vec4& vec4::multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}


	//divide two vectors 
	vec4& vec4::divide(const vec4& other)
	{

		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;

	}


	// adds two vectors with + operator 
	vec4 operator +(vec4 left, const vec4& right)
	{
		return left.add(right);
	}


	//subtracrs two vectors with - operator
	vec4 operator -(vec4 left, const vec4& right)
	{
		return left.subtract(right);
	}


	//multiplies two vectors with * operator
	vec4 operator *(vec4 left, const vec4& right)
	{
		return left.multiply(right);
	}


	//divides two vectors with / operator
	vec4 operator /(vec4 left, const vec4& right)
	{
		return left.divide(right);
	}


	// adds two vectors with += operator 
	vec4& vec4 ::operator +=(const vec4& other)
	{
		return add(other);

	}

	//subtracrs two vectors with -= operator
	vec4& vec4 ::operator -=(const vec4& other)
	{
		return subtract(other);

	}

	//multiplies two vectors with *= operator
	vec4& vec4 ::operator *=(const vec4& other)
	{
		return multiply(other);

	}

	//divides two vectors with /= operator
	vec4& vec4 ::operator/=(const vec4& other)
	{
		return divide(other);

	}

	//vector comparasion by overloading == operator method 
	bool vec4 ::operator==(const vec4& other)
	{
		 return x == other.x && y == other.y && z ==other.z && w==other.w;
	}

	//vector comparasion by overloading == operator method 
	bool vec4 ::operator !=(const vec4& other)
	{
		return !(*this == other);
	}



	//output stream 
	std::ostream& operator <<(std::ostream& stream, const vec4& vector)
	{
		 
		stream << "vec4 : (" << vector.x << " , " << vector.y << ", " << vector.z <<" ," << vector.w  << " )";
		return stream;
	}


}}