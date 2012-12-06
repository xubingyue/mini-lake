#include <lake/trace.hpp>
#include <lake/cmdline.hpp>
#include <lake/error_info.hpp>

namespace lake{

	void cmdline::parse_property(const std::string & source)
	{
		std::string val;

		size_t split = source.find('=');

		std::string key = source.substr(0,split);

		if(split != source.npos)
		{
			val = source.substr(split + 1);
		}

		_properties.insert(key,val);
	}

	cmdline::cmdline(int args, char ** argv)
	{
		bool propertyValueExpect = false;

		bool outputDirectoryExpect = false;

		for(int i = 1; i < args; ++ i)
		{
			std::string arg(argv[i]);

			if(_lifecycleOrGoal.empty())
			{
				//parse the first arg of command line.
				
				if(arg.find("-D") != arg.npos || arg.find("-o") != arg.npos)
				{
					trace::write(trace::error,"invalid input, first argument must be Goal or Lifecycle name");

					throw std::runtime_error("parse command line error !!!!");
				}

				_lifecycleOrGoal = arg;

				continue;
			}

			if(propertyValueExpect)
			{
				if(arg.find("-D") != arg.npos || arg.find("-o") != arg.npos)
				{
					trace::write(trace::error,"invalid input, expect property key value pair(%d)",i - 1);

					throw std::runtime_error("parse command line error !!!!");
				}

				propertyValueExpect = false;

				parse_property(arg);

				continue;
			}

			if(outputDirectoryExpect)
			{
				if(arg.find("-D") != arg.npos || arg.find("-o") != arg.npos)
				{
					trace::write(trace::error,"invalid input, expect output directory (%d)",i - 1);

					throw std::runtime_error("parse command line error !!!!");
				}

				outputDirectoryExpect = false;

				_outputDirectory = arg;

				continue;
			}

			if(arg.find("-D") != arg.npos)
			{
				arg = arg.substr(2);

				if(arg.empty()) { propertyValueExpect = true; continue;}

				parse_property(arg);

				continue;
			}

			if(arg.find("-o") != arg.npos)
			{
				arg = arg.substr(2);

				if(arg.empty()) { outputDirectoryExpect = true; continue;}

				_outputDirectory = arg;

				continue;
			}

			if(i == args - 1) _workspace = arg;
		}

		if(_outputDirectory.empty()) _outputDirectory = "./";

		if(_workspace.empty()) _workspace = "./";
	}

}