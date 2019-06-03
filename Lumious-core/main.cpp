#pragma once


#include "src/graphics/window.h" 
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/graphics/rectangle.h"
#include "src/utils/timer.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers\group.h"
#include "src/graphics/Color.h"
#include <iostream>


using namespace Lumious;
using namespace graphics;
using namespace maths;

int main(int argc, char* argv[] ) 
{
	 //creating window

	Window window("Lumious!", 960, 540);


	//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
   //std::cout << glGetString(GL_VERSION) << std::endl;

	

// creating shader and reading from shader files 
	Shader& shader = *new Shader("res/shaders/basic.vert", "res/shaders/basic.frag");;
	Shader& shader2 = *new Shader("res/shaders/basic.vert", "res/shaders/basic.frag");;


	TileLayer layer(&shader);
	
	TileLayer layer2(&shader2);
	
	Rect& s2 = *new Rect(2, 2, 2.0f, 2.0f, Color::Red);
	
	for ( float y=0; y < 9.0f; y+= 0.1f)
	{
		for (float x=0; x < 16.0f; x +=0.1f)
		{
			 Rect& s = *new Rect(x, y, 0.09f, 0.09f, Color::Aqua );
			layer.add(&s);
		}
		
	}
	
	layer2.add(&s2);
	
	
	

	//create Timer
	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	
	//game loop
	while (!window.closed())
	{

		//Start Renderering
		//clearing the window
		window.clear();
		
		
		/*mat4 mat = mat4::translation(vec3(5, 5, 5));
		mat4 mat2 = mat4::rotation( time.elapsed()*100.0f, vec3(0, 0, 1));

		//mat4 mat3 = mat4::translation(vec3(-5, -5, -5));
		//mat = mat2;
		//mat = mat * mat3;
		//shader.enable();
		//shader.setUniformMat4("ml_matrix", mat2);

		shader2.enable();
		shader2.setUniformMat4("ml_matrix", mat2);
		*/

		// gets the mouse position 
		double x, y;
		window.getMousePosition(x, y);
		
		//uniform light_pos set to mous pposition to move when mous is moved
		shader.enable();
		shader.setUniform2f("light_pos", vec2(5, 5));
		
		//uniform light_pos sets the light pposition to ther mouse position so you can move point light when mouse is moved
		shader.setUniform2f("light_pos", vec2((float)(x *16.0f / window.getWidth()), (float)(9.0 -  y*9.0f / window.getHeight())));
		
		
		shader2.enable();
		//shader2.setUniform2f("light_pos", vec2((float)(x *16.0f / window.getWidth()), (float)( 9.0 - y*9.0f / window.getHeight())));
		
		//rendering layer
		layer.render();
		layer2.render();
		
		
		/*
		#if BATCH_RENDERER
				renderer.begin();
		#endif
				// submit Sprites
			   for (size_t i = 0; i < sprites.size(); i++)
			   {

				   renderer.submit(sprites[i]);
				   //printf("%d sprites\n" , sprites[i]);
			   }


		#if BATCH_RENDERER
			   //Stop Renderering
			   renderer.end();

		#endif

			   //flush and clean opengl glMapBuffer
				renderer.flush();
				*/

		
	   //updating the window every frame
		window.update();

		

		frames++;
		if (time.elapsed() - timer >= 1.0f)
		{

			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		} 


		// keyboard imput for Key A
		

		if (window.isKeyPressed(GLFW_KEY_A))
		{

			std::cout << " A" << std::endl;
		}

		if (window.isKeyPressed(GLFW_KEY_S))
		{
			std::cout << " S" << std::endl;
		}
		if (window.isKeyTyped(GLFW_KEY_R))
		{
			std::cout << "Rotating Square" << std::endl;
			mat4 transform =maths::mat4::translation(vec3(5, 5, 0));
			layer2.getRenderer()->push(transform);
			std::string  str = "nikhil";
			std::cout << str << std::endl;
		}

		if (window.isKeyPressed(GLFW_KEY_LEFT))
		{
			std::cout << "Left";
			mat4 transform = maths::mat4::translation(vec3(-1, 0, 0));
			layer2.getRenderer()->push(transform);
		}

		if (window.isKeyPressed(GLFW_KEY_RIGHT))
		{
			mat4 transform = maths::mat4::translation(vec3(1, 0, 0));
			layer2.getRenderer()->push(transform);
		}

		if (window.isKeyPressed(GLFW_KEY_D))
		{

			std::cout << " D" << std::endl;
		}

		if (window.isKeyTyped(GLFW_KEY_W))
		{
			
		}


		if (window.isMouseButtonClicked(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << " Clicked" << std::endl;
		}

		//keyboard imput for Key ESCAPE
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
		{
			std::cout << " Pressed" << std::endl;
		}
	}

return 0;
}




