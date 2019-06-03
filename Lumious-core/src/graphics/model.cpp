                                        #include "model.h"

namespace Lumious { namespace graphics {

	Model::Model(const char* filpeath)
		:_filepath(filpeath) 
	{ 
		

	}

	void Model::render()
	{
		bool loading = true;
		std::vector<maths::vec3>  _vertices;
		std::vector<maths::vec2>  _uvs;
		std::vector<maths::vec3>  _normals;


		if (loading)
		{
			//loading = Utils::FIleUtils::loadObj(_filepath, _vertices, _uvs, _normals);
		}

		
	}


	void Model:: load()
	{

		std::string objFile;
		//utils::FIleUtils::read_Obj(_filepath);
	}
	
	
	const char* Model:: getPath()
	{
		return _filepath;
	}


}}