#pragma once 

#include <iostream> 
#include <vector>
#include <GL\glew.h>
#include "../utils/fileutils.h"
#include "../maths/maths.h"
namespace Lumious {namespace graphics {

	class Shader
	{

		private :

			GLuint m_ShaderID;  // GLEW unsigned shader id 

			const char *m_VertPath;    // vertex path
			const char	*m_FragPath;  // fragment path

	public :

		// Shader constructor and destrictor
		Shader(const char *vertPath , const char *fragPath);
		~Shader();

		void enable() const;
		void disable() const;


		//uniform methods 
		void setUniform1f(const GLchar * name, float value);
		void setUniform1i(const GLchar * name, int value);

		// vector uniform methods
		void setUniform2f(const GLchar * name, const maths::vec2& vector);
		void setUniform3f(const GLchar * name, const maths::vec3& vector);
		void setUniform4f(const GLchar * name, const maths::vec4& vector);

		//matrix uniform methods
		void setUniformMat4(const GLchar * name, const maths::mat4& matrix);

	private :

		//loades the shader by taking in a shader id 
		GLuint load();

		//Gets the uniform  Location 
		GLint getUniformLocation(const GLchar *name);


	};

}}