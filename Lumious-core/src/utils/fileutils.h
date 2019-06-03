#pragma once 

#include <string>
#include <vector>
#include "../maths/maths.h"
#include <fstream>
#include <sstream>

namespace Lumious { namespace utils {

	class FIleUtils
	{
		public:
			// reads a file
			static std::string read_file(const char  *filepath)
		{
			//opens the file in a certain mode 
			FILE *file = fopen(filepath, "rt");

			// finds the end of the file 
			fseek(file, 0, SEEK_END);

			//retrieves the length of the file 
			unsigned long length = ftell(file);

			//character array called data 
			char *data = new char[length + 1];

			memset(data, 0, length + 1);

			//sets the seek 
			fseek(file, 0, SEEK_SET);

			//readds the file 
			fread(data, 1, length + 1, file);

			//closes the file 
			fclose(file);

			std::string result(data);

			//deletes data
			delete[] data;

			return result;


		} // end of method 


			/*static bool  loadObj( const char *filepath ,std::vector<maths::vec3> out_vertices, std::vector<maths::vec2> out_uvs, std::vector<maths::vec3> out_normals)
		  {

		  bool reading = true;
		  //vertex , uv , and vertex normalsindices
		  std::vector< unsigned int> vertex_indices;
		  std::vector< unsigned int> uv_indices;
		  std::vector< unsigned int> normal_indices;

		  //temp vertex , uv , and vertex normalsindices
		  std::vector<maths::vec3> temp_vertices;
		  std::vector<maths::vec2> temp_uvs;
		  std::vector<maths::vec3> temp_normals;

		  //opens the file in a certain mode
		  FILE *file = fopen(filepath, "r");

		  if (file == NULL) {
		  printf("Impossible to open the file !\n");
		  return false;
		  }


		  while (reading)
		  {

		  // reading file
		  char lineHeader[128];
		  // read the first word of the line
		  int res = fscanf(file, "%s", lineHeader);
		  if (res == EOF)
		  break; // EOF = End Of File. Quit the loop.

		  //reading vertices
		  if (strcmp(lineHeader, "v") == 0) {

		  maths::vec3 vertex;
		  fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
		  temp_vertices.push_back(vertex);
		  }

		  //reading uv's
		  else if (strcmp(lineHeader, "vt") == 0) {

		  maths::vec2 uv;
		  fscanf(file, "%f %f %f\n", &uv.x, &uv.y );
		  temp_uvs.push_back(uv);
		  }

		  //reading normals
		  else if (strcmp(lineHeader, "vn") == 0) {

		  maths::vec3 normals;
		  fscanf(file, "%f %f %f\n", &normals.x, &normals.y, &normals.z);
		  temp_normals.push_back(normals);
		  }

		  //reading faces
		  else if (strcmp(lineHeader, "f") == 0) {

		  //vertices
		  std::string vertex1, vertex2, vertex3;

		  //vertex indices
		  unsigned int vertex_index[3], uv_index[3], normal_index[3];

		  int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertex_index[0], &uv_index[0], &normal_index[0]);
		  if (matches != 9) {
		  printf("File can't be read by our simple parser : ( Try exporting with other options\n");
		  return false;
		  }

		  vertex_indices.push_back(vertex_index[0]);
		  vertex_indices.push_back(vertex_index[1]);
		  vertex_indices.push_back(vertex_index[2]);
		  uv_indices.push_back(uv_index[0]);
		  uv_indices.push_back(uv_index[1]);
		  uv_indices.push_back(uv_index[2]);
		  normal_indices.push_back(normal_index[0]);
		  normal_indices.push_back(normal_index[1]);
		  normal_indices.push_back(normal_index[2]);

		  maths::vec3 vertex;
		  for (unsigned int i = 0; i < vertex_indices.size(); i++) {

		  //vertex  index
		  unsigned int vertex_Index = vertex_indices[i];
		  vertex = temp_vertices[vertex_Index - 1];
		  }

		  maths::vec2 uv;
		  for (unsigned int j = 0; j < uv_indices.size(); j++) {

		  unsigned int uv_Index = uv_indices[j];
		  maths::vec2 uv = temp_uvs[uv_Index - 1];
		  }



		  maths::vec3 normal;
		  for (unsigned int k = 0; k < normal_indices.size(); k++) {

		  unsigned int normal_Index = normal_indices[k];
		  maths::vec3 normal = temp_normals[normal_Index - 1];
		  }


		  out_vertices.push_back(vertex);
		  out_uvs.push_back(uv);
		  out_normals.push_back(normal);
		  reading = false;
		  }
		  }
		  glBufferData(GL_ARRAY_BUFFER, out_vertices.size() * sizeof(std::vector<maths::vec3>), &out_vertices[0], GL_STATIC_DRAW);
		  fclose(file);
		  return reading;
		  }
		  */
			
			/*static void read_Obj(const char *filepath)
			{
				std::stringstream str;
				
				std::ifstream file(filepath);
			
				
				std::string line="";
				std ::string data;
				float x;
				float y;
				float z;
				
				
				maths::vec3 vertex(x , y , z);
				std::vector<maths::vec3> vertices;
				std::string vertex_x;
				std::string vertex_y;
				std ::string  vertex_z;
				
				
				if (file.fail())
				{
					file.close();
					std::cout << "cannot open file" << std ::endl;
					
				}
				else if (file.is_open())
				{

					while (getline(file, line) )
					{
						data = line.substr(0 ,1);
						if(data =="vt"|| data == "vm" || data == " f")
						{
							continue;
	
						}
						else if ( data =="v" )
						{
							
							 vertex_x = line.substr(1, 8);
							 vertex_y = line.substr(11, 8);
							 vertex_z = line.substr(21, 8);
							vertex.x = stof(vertex_x);
							vertex.y = stof(vertex_y);
							vertex.z = stof(vertex_z);
							std::cout << vertex.x <<" " << vertex.y <<  " " << vertex.z << std::endl;
						}
						 
						
						
					}

						
						
				
					file.close();
					
					
				
					
				}//end of else if block
				
		}//end of method */


	};

}}


