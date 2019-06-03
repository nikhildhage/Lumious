#include "vec3.h"

namespace Lumious { namespace maths {

	//default vector constructor 


		

	vec3::vec3(const int& x, const int& y, const int& z)
		:x(0), y(0), z(0)
	{
	}

	//non-default vector constructor 
	 vec3 :: vec3(const float& x, const float& y, const float& z)
		 :x(x), y(y), z(z)
	 {

		
	}

	
	 vec3::vec3(const double& x, const double& y, const double&z) 
		 :x(x), y(y), z(z)
	 {

	 }


	
	// add two vectors 
	vec3& vec3 ::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}


	//subtract two vectors
	vec3& vec3::subtract(const vec3& other)
	{

		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}


	//multiply two vectors
	vec3& vec3::multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}


	//divide two vectors 
	vec3& vec3::divide(const vec3& other)
	{

		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;

	}


	// adds two vectors with + operator 
	vec3 operator +(vec3 left, const vec3& right)
	{
		return left.add(right);
	}


	//subtracrs two vectors with - operator
	vec3 operator -(vec3 left, const vec3& right)
	{
		return left.subtract(right);
	}


	//multiplies two vectors with * operator
	vec3 operator *(vec3 left, const vec3& right)
	{
		return left.multiply(right);
	}


	//divides two vectors with / operator
	vec3 operator /(vec3 left, const vec3& right)
	{
		return left.divide(right);
	}


	// adds two vectors with += operator 
	vec3& vec3 ::operator +=(const vec3& other)
	{
		return add(other);

	}

	//subtracrs two vectors with -= operator
	vec3& vec3 ::operator -=(const vec3& other)
	{
		return subtract(other);

	}

	//multiplies two vectors with *= operator
	vec3& vec3 ::operator *=(const vec3& other)
	{
		return multiply(other);

	}

	//divides two vectors with /= operator
	vec3& vec3 ::operator/=(const vec3& other)
	{
		return divide(other);

	}

	//vector comparasion by overloading == operator method 
	bool vec3 ::operator==(const vec3& other)
	{
		 return x == other.x && y == other.y && z==other.z;
	}

	//vector comparasion by overloading == operator method 
	bool vec3 ::operator !=(const vec3& other)
	{
		return !(*this == other);
	}



	//output stream 
	std::ostream& operator <<(std::ostream& stream, const vec3& vector)
	{

		stream << "vec3 : (" << vector.x << " ," << vector.y << " ," <<  vector.z << ")";
		return stream;
	}


}}