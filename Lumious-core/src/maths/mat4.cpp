       #pragma once 


#include "mat4.h"
#include "maths.h"

namespace Lumious { namespace maths {

		// mat4 constructor : sets elements to zero 
		mat4::mat4()
		{

			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;


		}

		// mat4 constructor : sets the main diagonal 
		mat4::mat4(float diagonal)
		{

			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;


		}


		mat4:: mat4(const  vec4& diagonal)
		{

			elements[0 + 0 * 4] = diagonal.x;
			elements[1 + 1 * 4] = diagonal.y;
			elements[2 + 2 * 4] = diagonal.z;
			elements[3 + 3 * 4] = diagonal.w;

		}


		// constructs a mat4  identity matrux 
		mat4 mat4::identity()
		{

			return mat4(1.0f);

		}


		//mulriplies two 4 by 4 matrices
		mat4& mat4::multiply(const mat4& other)
		{
			 // data is a 4 x 4 matrix constructed from one array
			float data[16];

			//iterates throught y rows 
			for (int y = 0; y < 4; y++)
			{
				//iterates throught x collums
				for (int x = 0; x < 4; x++)
				{

					//iterates throught e elements 
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{

						//adds all the elements  in the matrix 
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					} //end of elemnts loop 

				   // elements at index = sum of mutiplyed  matrix elements 
					data[x + y * 4] = sum;

				} // end of collums koop

			} //end of rows loop 

			memcpy(elements, data, 16 * sizeof(float));
			return *this;
		} // end of method 
		
		
		vec3 mat4::multiply(const vec3 & other) const 
		{
			return vec3
			(
				columns[0].x *other.x + columns[1].x *other.y + columns[2].x *other.z + columns[3].x ,
				columns[0].y *other.x + columns[1].y *other.y + columns[2].y *other.z + columns[3].y, 
				columns[0].z *other.x + columns[1].z *other.y + columns[2].z *other.z + columns[3].z 
			);
		}

		vec4 mat4::multiply(const vec4 & other) const 
		{
			return vec4
			(

				columns[0].x *other.x + columns[1].x *other.y + columns[2].x *other.z + columns[3].x *other.w,
				columns[0].y *other.x + columns[1].y *other.y + columns[2].y *other.z + columns[3].y *other.w,
				columns[0].z *other.x + columns[1].z *other.y + columns[2].z *other.z + columns[3].z *other.w,
				columns[0].w *other.x + columns[1].w *other.y + columns[2].w *other.z + columns[3].w *other.w
			);
		}

		float PI = M_PI;
		// utility method , converts degrees to radians 
		float toRadians(float degrees)
		{
			return degrees *(  PI / 180.00f);
		}


		//mulriplies two 4 by 4 matrices with the *= operator 
		
	
		mat4 maths::operator*(mat4 left, const mat4 & right)
		{
			return left.multiply(right);
		}


		mat4  mat4 :: operator *= (const mat4  other)
		{
			return multiply(other);
		}


		vec3 operator*(const mat4& left,  const vec3 & right)
		{
			 return left.multiply(right);
		}

		vec4 operator*(const mat4 & left, const vec4 & right)
		{
			return left.multiply(right);
		}
		
		
	

		// constructs a mat4 orthographic matrix 
		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{

			// start with identity matrix 
			mat4 result(1.0f);

			//main diagonal 
			result.elements[0 + 0 * 4] = 2 / (right - left);

			result.elements[1 + 1 * 4] = 2 / (top - bottom);

			result.elements[2 + 2 * 4] = 2 / (near - far);


			// 3rd colum 
			result.elements[0 + 3 * 4] = (left + right) / (left - right);

			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);

			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;

		}


		//  constructs a mat4  perspective matrix 
		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{


			// start with identity matrix 
			mat4 result(1.0f);

			float q = 1.0f / (tan(toRadians(0.05f *fov)));

			float a = q / (aspectRatio);

			float b = (near + far) / (near - far);

			float c = (2.0f *near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;

			result.elements[1 + 1 * 4] = q;

			result.elements[2 + 2 * 4] = b;

			result.elements[3 + 2 * 4] = -1.0f;

			result.elements[2 + 3 * 4] = c;

			return result;

		}


		//   constructs a mat4 translation matrix 
		mat4 mat4::translation(const vec3& translation)
		{
			// start with identity matrix 
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;

			result.elements[1 + 3 * 4] = translation.y;

			result.elements[2 + 3 * 4] = translation.z;

			return result;

		}


		//constructs a mat4 rotation matrix that rotates at an angle on an axis 
		mat4  mat4::rotation(float angle, const vec3& axis)
		{


			// start with identity matrix 
			mat4 result(1.0f);


			// r angle in radians , c calculates cosine of r , s calculates sine of r 
			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);

			//omc is 1 - c
			float omc = 1.0f - c;

			// x is the x-axis , y is y-axis , z is z-axis
			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			// x-axis rotation 
			result.elements[0 + 0 * 4] = x* omc + c;

			result.elements[1 + 0 * 4] = y* x * omc + z *s;

			result.elements[2 + 0 * 4] = x* z * omc - y* s;

			// y-axis rotation 
			result.elements[0 + 1 * 4] = x* z * omc - z* s;

			result.elements[1 + 1 * 4] = y* omc + c;

			result.elements[2 + 1 * 4] = x* z * omc + x* s;

			//z-axis rotation 
			result.elements[0 + 2 * 4] = x* z * omc + y* s;

			result.elements[1 + 2 * 4] = y* z *omc - x* s;

			result.elements[2 + 2 * 4] = z* omc + c;

			return result;


		}

		// mat4 scale matrix 
		mat4 mat4::scale(const vec3& scale)
		{

			// start with identity matrix 
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;

			result.elements[1 + 1 * 4] = scale.y;

			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}
	
}}
