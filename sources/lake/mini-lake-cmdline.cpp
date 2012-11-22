#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <lake/mini-lake-cmdline.hpp>

namespace lake{

	cmdline::cmdline(int args, char ** argv)
	{
		parse(args,argv);
	}

	cmdline::~cmdline()
	{

	}

	void cmdline::parse(int args, char ** argv)
	{
		std::cout << "run mini-lake : " << argv[0] << std::endl;

		bool expectValue = false;

		for(int i = 1; i < args; ++ i)
		{
			std::string arg(argv[i]);

			if(arg.find("-D") == 0) // this is pom::property define arg
			{
				if(expectValue) { throw std::runtime_error("expect pom::property value pair");} 

				if(arg.length() == sizeof("-D") - 1){ expectValue = true; continue; }

				_properties.push_back(pom::property(arg.substr(sizeof("-D") - 1)));

				std::cout << "[lake cmdline] (pom::property,Value) => " << _properties.back().name() << "=" << _properties.back().value() << std::endl;

				continue;
			}

			if(expectValue){ _properties.push_back(pom::property(arg)); expectValue = false; }

			if(!_plugin.empty() || !_lifecycle.empty()){ throw std::runtime_error("can only define one goal or lifecycle");}
			
			//parse the goal or life cycle

			std::string::size_type found = arg.find(":");

			if(arg.npos != found)
			{
				_plugin = arg.substr(0,found);

				_pluginGoal = arg.substr(found + 1);

				if(_plugin.empty()) { throw std::runtime_error("expect goal's plugin name"); }

				std::cout << "[lake cmdline] (Plugin,Goal) =>" << _plugin << ":" << _pluginGoal << std::endl;

				continue;
			}

			for(size_t i = 0; i < sizeof(config::BuildinLifeCycle)/sizeof(const char*); ++ i)
			{
				if(arg == config::BuildinLifeCycle[i]) 
				{
					std::cout << "[lake cmdline] Lifecycle => " << arg << std::endl;

					_lifecycle = arg; break;
				}
			}
		}
	}
}