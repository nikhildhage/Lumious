#pragma once 

#include <array>
namespace Lumious { namespace maths {
		
	// Template Class Matrix
	template<typename T, unsigned int M,   unsigned int  N>
		class Matrix
		{

			
			protected:
				//typedefs

				T m_elements[M][N];

				//methids

				T getArray() { return array;}


			
			public:
				
				Matrix() { fill(0); }
					
				 T  getRowSize();
				
				 T getColumSize();
				 
				
				 void fill(T e);
				 
				 void print();

				 //friend operatir{};
	};
	
		template<typename T, unsigned int M, unsigned int N >
		T Matrix<T, M, N> ::getRowSize() { return M; }

		template<typename T, unsigned int M, unsigned int N >
		T Matrix<T, M, N> ::getColumSize() { return N; }
		
		template<typename T, unsigned int M, unsigned int N >
		void Matrix<T, M, N>::fill(T e)
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					m_elements[i][j] = e;
				}
			}
		}

		template<typename T , unsigned int M, unsigned int N >
		void  Matrix<T , M, N>::print()
		{

			for (unsigned int i = 0; i < getRows(); i++)
			{
				for (unsigned int j = 0; j < getColums(); j++)
				{
					std::cout << m_elements[i][j] << " ,";
				}

				std::cout << std ::endl;
			}
		}
		


}}




 
