#include <lake/mini-lake-plugins.hpp>

namespace lake{namespace plugins{

	plugin::plugin(const std::string & path) :_path(path)
	{
		check();//check the plugin contract
	}

	plugin::~plugin()
	{

	}

	void plugin::check()
	{
		std::stringstream stream;

		stream << "check the plugin failed !!! (path) ==> " << _path << std::endl;

		throw std::runtime_error(stream.str().c_str());
	}

	void plugin::run_goal(pom::project * /*proj*/,const std::string & /*goal*/)
	{

	}


	//////////////////////////////////////////////////////////////////////////

	manager::~manager()
	{
		plugins::iterator iter,end = _plugins.end();

		for(iter = _plugins.begin(); iter != end; ++ iter)
		{
			delete iter->second;
		}
	}

	void manager::run_goal(pom::project * proj,const std::string & name, const std::string & goal)
	{
		plugins::iterator iter = _plugins.find(name);

		if(iter == _plugins.end())
		{
			std::string path = name;

			iter = _plugins.insert(std::make_pair(name,new plugin(path))).first;
		}

		iter->second->run_goal(proj,goal);
	}
}}