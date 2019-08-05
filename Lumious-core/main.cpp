#pragma once


#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/utils/timer.h"
#include "src/maths/maths.h"
#include "src/graphics/rectangle.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers\group.h"
#include "src/graphics/Color.h"
#include <iostream>




using namespace Lumious;
using namespace graphics;
using namespace maths;

int main(int argc, char* argv[] ) 
{
	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	int renderables = 0;
	
	//creating window
	Window window ("Lumious",900  ,540);
	
	//creating shader and reading from shader files 
	Shader& shader = *new Shader("res/shaders/basic.vert", "res/shaders/basic.frag");;
	Shader& shader2 = *new Shader("res/shaders/basic.vert", "res/shaders/basic.frag");;

	vec2 aspectRatio(16.0f, 9.0f);
	TileLayer layer(&shader);
	
	TileLayer layer2(&shader2);
	
	for(float y=0; y < aspectRatio.y; y+=0.05f)
	{

		for (float x = 0; x < aspectRatio.x; x += 0.05f)
		{
			Rect* s3 = new Rect(x, y, 0.04f, 0.04f, Color::Fushhia);
			layer.add(s3);
		}
	}

	Rect* s2 = new Rect(2, 2, 2.0f, 2.0f, Color::Green);
	layer2.add(s2);

	
	
	
	

	//create Timer
	renderables = layer.getSize()+ layer2.getSize();
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
		
		//updating the window every frame
		window.update();
		
		frames++;
		if (time.elapsed() - timer >= 1.0f)
		{

			timer += 1.0f;
			printf("%d fps\n", frames);
			printf("%d Renderables\n", renderables);
			frames = 0;
		} 


		// keyboard imput for Key A
		

		
	}
	
return 0;
}




