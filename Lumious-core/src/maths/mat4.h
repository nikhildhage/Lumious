#pragma once 

#include "vec3.h"
#include "vec4.h"
#include "maths_func.h"
namespace Lumious { namespace maths {

	

	struct mat4  
	{

		union 
		{
			//array of elements for mat4
			float elements[4 * 4];
			vec4 columns[4];

		};
	
		//mat4 constructors 
		mat4();
		mat4(float diagonal);

		mat4(const vec4 & diagonal);

		
		//mat4 meethods 

		//  mat4 identity matrix 
		static mat4 identity();

		//mulriplies two 4 by 4 matrices
		mat4& multiply(const mat4& other);

		//mulriplies two 4 by 4 matrices with the * operator 
		friend mat4 operator *(mat4 left, const mat4& right);

		
		//mulriplies two 4 by 4 matrices with the *= operator 
		mat4 operator *= (const mat4  other);

		vec3 multiply(const vec3& other) const;
		friend vec3 operator*(const mat4& left,  const vec3& right);

		vec4 multiply(const vec4& other) const;
		friend vec4 operator*(const mat4& left, const vec4& right);

		// mat4 orthographic matrix 
		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
		
		// mat4  perspective matrix 
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		//  mat4 translation matrix 
		static mat4 translation(const vec3& translation );

		// mat4 rotation matrix 
		static mat4 rotation(float angle, const vec3& axis);

		// mat4 scale matrix 
		static mat4 scale (const vec3& scale );

		//inline const float* getMatrixArray() const { return mat.elements; };
		//inline const float* getMatrixSize() const { return mat.elements.size(); };

	};


}}