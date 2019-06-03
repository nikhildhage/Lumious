#pragma once


#include <windows.h>


  namespace Lumious{  



	  class Timer
	  {

	     private :

			 LARGE_INTEGER   m_Start;     // startt timer variable 
			 float m_frequency;  //frequency value
			 float m_ratio;

	     public :

			 //Timer Constructor 
			 Timer()
			 {
				      LARGE_INTEGER   frequency;  // frequency of Timer
				     // performance frequency variable 
					 QueryPerformanceFrequency(&frequency);  // query's permformance frequency
					 m_ratio = 1.0;
					 m_frequency = m_ratio / frequency.QuadPart;
					 QueryPerformanceCounter(&m_Start);   //  a counter to Query performance 


			 }


			 // resetts timer 
			 void reset()
			 {
                 QueryPerformanceCounter(&m_Start);
			 }

			


			 double   getFrequency()
			 {
				 return  m_frequency;
			 }


			 //calculatttes elapsed time
			 float elapsed()
			 {

				 LARGE_INTEGER current;
				QueryPerformanceCounter(&current);
				 unsigned   __int64 cycles = current.QuadPart - m_Start.QuadPart;   //  calculatte elapsed time 
				
				 return (float)cycles*m_frequency;   // calculate elapsed time *frequnecy
			 }





	  };

  }