/**
* 
* @file     mini-lake-plugins
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_PLUGINS_HPP
#define MINI_LAKE_PLUGINS_HPP

#include <lua/lua.hpp>
#include <lake/mini-lake-pom.hpp>
#include <lake/mini-lake-utility.hpp>


namespace lake{namespace plugins{

	class plugin : private nocopyable
	{
	public:

		plugin(const std::string & path);

		~plugin();

		void run_goal(pom::project * proj,const std::string & goal);

	private:
		
		void check();

		void open_lua();

		void close_lua();

	private:

		std::string				_path;

		lua_State				*L;
	};


	//////////////////////////////////////////////////////////////////////////

	class manager : private nocopyable
	{
	public:

		typedef std::map<std::string,plugin*>						plugins;

		~manager();

		void run_goal(pom::project * proj,const std::string & name, const std::string & goal);

	private:

		plugins						_plugins;
	};
}}

#endif //MINI_LAKE_PLUGINS_HPP

