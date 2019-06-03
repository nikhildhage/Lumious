#pragma once 



#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace Lumious {namespace graphics {

#define MAX_KEYS 1024   //number of heys on keyboard
#define MAX_BUTTONS 32   //number of mouse button

	class Window
	{
		//private members
		private:
			
			const char*m_Title;     //Window title 
			int m_Width, m_Height;  //WIndow Width and height
			GLFWwindow *m_Window;  // GLFW pointer to Window object
			bool m_Closed;        // boolean for closing window

			//keyboard and moouse imput
			bool m_Keys[MAX_KEYS];
			bool m_KeyStates[MAX_KEYS];
			bool m_KeyTyped[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			bool m_MouseButtonStates[MAX_BUTTONS];
			bool m_MouseButtonClicked[MAX_BUTTONS];
			//mouse cursor x, y postion  
			double mx, my;

			//public methods
		public:

			Window(const char *title, int width, int height);  //Wininodw constructor
			~Window();  // Window destructor
			void clear() const; // Window clear method 
			void update(); //Window update method 
			bool closed() const;  //Window 

			// keyboard and mouse imput methods
			bool isKeyPressed(unsigned int keyCode) const;
			bool isKeyTyped(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			bool isMouseButtonClicked(unsigned int button) const;
			void getMousePosition(double &x, double &y) const;

			//getters 

			inline char getTitle() const  { return *m_Title; };  //gets the window title
			inline int getWidth() const  { return m_Width; };    //gets the winodw width
			inline int getHeight() const  { return m_Height; };  //gets the window height 

			//private methods
			private:

			//Winodw init method
			bool init();
			 
			friend static void window_resize( GLFWwindow *window , int  width, int height);
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);




	};


}}
