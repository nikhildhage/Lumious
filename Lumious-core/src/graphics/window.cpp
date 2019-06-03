#pragma once 

#include "Window.h"
namespace Lumious { namespace graphics {
	
		//Winodw constructor
		 Window::Window(const char *title, int width, int height)
			: m_Title(title) ,m_Width(width) , m_Height(height)
		{

			
			if (!init())
			{
				glfwTerminate();


			}


			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
				m_KeyStates[i] = false;
				m_KeyTyped[i] = false;

			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
				m_MouseButtonStates[i]=false;
				m_MouseButtonClicked[i] = false;
			}
		}


		//Window destructor
		Window ::~Window()
		{
			glfwTerminate();
		}


		//Intializes evrything for the window r
		bool  Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "ERROR : Failed to intialize GLFW!" << std::endl;
				return false;
			}


			//creates the window
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				//Terminates the window 
				glfwTerminate();

				std::cout << "Failed to create GLFW Window! " << std::endl;
				return false;
			}

			//makes the window the current contxt
			glfwMakeContextCurrent(m_Window);


			// GLFW callbacks
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetFramebufferSizeCallback(m_Window , window_resize );
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glfwSwapInterval(0);
			

			if (!glewInit() == GLEW_OK)
			{
				std::cout << "ERROR : Failed to intialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGl" << glGetString(GL_VERSION) << std::endl;
			return true;


		}


		//clears the window for rendering 
		void Window::clear() const

		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}



		//updates the window 
		void Window::update()
		{
			for (unsigned int i = 0; i < MAX_KEYS; i++)
			{

				m_KeyTyped[i] = m_Keys[i] && !m_KeyStates[i];
				
			}

			for (unsigned int i = 0; i < MAX_BUTTONS; i++)
			{

				m_MouseButtonClicked[i] = m_MouseButtons[i] && !m_MouseButtonStates[i];

			}

			memcpy(m_KeyStates, m_Keys, MAX_KEYS);
			memcpy(m_MouseButtonStates, m_MouseButtons, MAX_BUTTONS);

			
		


			for (unsigned int i = 0; i < MAX_BUTTONS; i++)
			{

				m_MouseButtonStates[i] = m_MouseButtons[i];

			}


			//Opengl Error checking 
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "Opengl Error :" << error << std :: endl;

			//pol events
			glfwPollEvents();

			//get the frame buffer size for the window
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);


			//swaps the window buffers
			glfwSwapBuffers(m_Window);
		}



		// closes the winodw when it is terminated
		bool Window::closed()  const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}


		void window_resize(GLFWwindow *window, int width, int height)
		{
			//resize viewport
			glViewport(0, 0, width ,height);
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win ->m_Width = width;
			win->m_Height = height;
		}
		



		bool Window::isKeyPressed(unsigned int keycode) const
		{
			if (keycode >= MAX_KEYS)
				return false;

			//std::cout  << m_Keys[keycode] << std::endl;
			return m_Keys[keycode];
		}

		bool Window::isKeyTyped(unsigned int keyCode) const
		{
			if (keyCode >= MAX_KEYS)
				return false;

			//std::cout  << m_Keys[keycode] << std::endl;
			return m_KeyTyped[keyCode];;
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			if (button >= MAX_BUTTONS)
				return false;

		
			return m_MouseButtons[button];
		}

		bool Window::isMouseButtonClicked(unsigned int button) const
		{
			if (button >= MAX_BUTTONS)
				return false;

			
			return m_MouseButtonClicked[button];;
		}

		void Window::getMousePosition(double &x, double &y) const
		 {
			x = mx;
			y = my;
		}


		// a kty callback for pressed or released keys
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win -> m_Keys[key] = action != GLFW_RELEASE;
		}


		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{


			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}



		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win-> mx = xpos;
			win-> my = ypos;
		}



	}}