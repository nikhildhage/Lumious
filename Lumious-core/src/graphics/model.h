#pragma once
#include "../utils/fileutils.h"
#include <GL\glew.h>
namespace Lumious { namespace graphics {
	
	class Model
	{
		
		protected :
			const char *_filepath;
			 std::vector<maths::vec3 > m_Vertices;

		public :
		
			Model(const char *_filepath );
			void render();
			const char* getPath();
			void load();


	};

}}