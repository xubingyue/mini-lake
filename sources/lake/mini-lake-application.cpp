#include <lake/mini-lake-application.hpp>

namespace lake{

	application::application(int args, char ** argv) : _cmdline(args, argv)
	{
		get_home_directory();
		
		/*-----------initialize default properties-----------------*/

		//the default plugin path
		_project.set_property(LAKE_PLUGIN_PATH,home() + "/plugins/");
	}

	application::~application()
	{

	}

	int application::run()
	{
		const cmdline::properties_type &properties = _cmdline.properties();

		cmdline::properties_type::const_iterator iter,end = properties.end();

		//run Global:Start goal ... 

		_pluginManager.run_goal(&_project,"Global","Start");

		//set the project properties from cmdline

		for(iter = properties.begin(); iter != end; ++ iter) _project.set_property(*iter);

		return 0;
	}

	//////////////////////////////////////////////////////////////////////////

	void application::get_home_directory()
	{
		_home = lake::getenv("MINI_LAKE_HOME");
#ifdef WIN32
		if(_home.empty())
		{
			char buffer[MAX_PATH] = {0};

			::GetModuleFileNameA(NULL,buffer,MAX_PATH);

			_home = buffer;

			_home = _home.substr(0,_home.find_last_of('\\'));

			_home += "\\..\\";
		}
#endif

		if(_home.empty()){ throw std::runtime_error("you must set environment variable MINI_LAKE_HOME"); }

		std::cout << "[lake message] MINI_LAKE_HOME=" << _home << std::endl;
	}
}