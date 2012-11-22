/**
* 
* @file     mini-lake-application
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_APPLICATION_HPP
#define MINI_LAKE_APPLICATION_HPP
#include <lake/mini-lake.hpp>
#include <lake/mini-lake-cmdline.hpp>
#include <lake/mini-lake-utility.hpp>
#include <lake/mini-lake-plugins.hpp>

namespace lake{

	class application : private nocopyable
	{
	public:

		application(int args, char ** argv);

		~application();

		int run();
	public:
		// get the mini lake home directory
		const std::string & home() const { return _home; }

	private:

		void get_home_directory();

	private:

		std::string				_home;

		pom::project			_project;

		cmdline					_cmdline;

		plugins::manager		_pluginManager;
	};
}
#endif //MINI_LAKE_APPLICATION_HPP

