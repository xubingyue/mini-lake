/**
* 
* @file     mini-lake-options
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_OPTIONS_HPP
#define MINI_LAKE_OPTIONS_HPP
#include <string>
#include <vector>
#include <lake/mini-lake-pom.hpp>
#include <lake/mini-lake-utility.hpp>

namespace lake{

	class cmdline : private nocopyable
	{
	public:

		typedef std::vector<pom::property> properties_type;
		
		cmdline(int args, char ** argv);

		~cmdline();

	public:

		const properties_type & properties() const { return _properties; }

		const std::string & plugin() const { return _plugin; }

		const std::string & goal() const { return _pluginGoal; }

		const std::string & lifecycle() const { return _lifecycle; }

	private:

		void parse(int args, char ** argv);

	private:

		properties_type						_properties;

		std::string							_plugin;

		std::string							_pluginGoal;

		std::string							_lifecycle;
	};

}

#endif //MINI_LAKE_OPTIONS_HPP

