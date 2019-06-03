#pragma once 


#include "shader.h"

namespace Lumious { namespace graphics {
	
	Shader::Shader(const char *vertPath, const char *fragPath)
	
		: m_VertPath(vertPath), m_FragPath(fragPath)

	{
		
		m_ShaderID = load();

	}

	// shader destructor 
	Shader :: ~Shader()
	{
		glDeleteProgram(m_ShaderID);

	}

	// loads the the shaders
	GLuint Shader::load()
	{

		
		//creates a program that linkes the vertex and fragments shader 
		GLuint program = glCreateProgram();

		//creates a vertex shader 
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);


		//creates a fragment shader
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);


		

		//gets vertex shader file
		std::string vertSourceString = utils ::FIleUtils::read_file(m_VertPath);

		//gets fragment shader file 
		std::string fragSourceString = utils::FIleUtils::read_file(m_FragPath);
		
		// vertex and fragment filepath sources 
		const char * vertSource = vertSourceString.c_str();
		
		const char * fragSource = fragSourceString.c_str();

		glShaderSource(vertex, 1, &vertSource, NULL);

		//compiles the vertex shader 
		glCompileShader(vertex);


		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

		// gets the shader info log if shader fails to compile
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector <char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			
			// prints the shader info log 
			std::cout << "Failed to compole Vertex shader!"<< std ::endl << &error[0] << std::endl; 

			// dektes vertex shader
			glDeleteShader(vertex);

			return 0;
		}



		glShaderSource(fragment, 1, &fragSource, NULL);

		//compiles the vertex shader 
		glCompileShader(fragment);


	
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

		// gets the shader info log if shader fails to compile
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector <char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);

			// prints the shader info log 
			std::cout << "Failed to compole fragment shader!" << std::endl << &error[0] << std::endl;

			// dektes vertex shader
			glDeleteShader(fragment);

			return 0;
		}

		// attaches the shaders to our program 
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		//links and validates the shadeers 
		glLinkProgram(program);
		glValidateProgram(program);

		//deletes the shaders 
		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	
	}


	//Gets the uniform  Location 
	GLint Shader::getUniformLocation(const GLchar *name)
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

	//uniform methods 
	void Shader::setUniform1f(const GLchar * name, float value)
	{

		glUniform1f(getUniformLocation(name), value);
	}

	void  Shader ::setUniform1i(const GLchar * name, int value)
	{

		glUniform1i(getUniformLocation(name), value);
	}


	// vector2D uniform methods
	void Shader :: setUniform2f(const GLchar * name, const maths::vec2& vector)
	{
		glUniform2f(getUniformLocation(name), vector.x ,vector.y);
	}

	//vector3D setUniform methods
	void  Shader::setUniform3f(const GLchar * name, const maths::vec3& vector)
	{
		
	    glUniform3f(getUniformLocation(name), vector.x, vector.y , vector.z);
	
	}

	//vector3D setUniform methods
	void Shader :: setUniform4f(const GLchar * name, const maths::vec4& vector)
	{

		glUniform4f(getUniformLocation(name), vector.x, vector.y , vector .z ,vector.w);
	
	}

	//matrix uniform methods
	void  Shader :: setUniformMat4(const GLchar * name, const maths::mat4& matrix)
	{
		glUniformMatrix4fv( getUniformLocation(name), 1, GL_FALSE, matrix.elements);

	}

	//enables the shader 
	void Shader :: enable() const
	{

		//turns shdadersa on
		glUseProgram(m_ShaderID);


	}


	//disables the shader 
	void Shader :: disable() const
	{
		// tuurns shaders off 
		glUseProgram(0);


	}
		
	
	}}