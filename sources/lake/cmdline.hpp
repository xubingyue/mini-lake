/**
* 
* @file     cmdline
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/03
*/
#ifndef LAKE_CMDLINE_HPP
#define LAKE_CMDLINE_HPP
#include <lake/uri.hpp>
#include <lake/configure.h>
#include <lake/properties.hpp>
#include <lemonxx/utility/utility.hpp>

namespace lake{

	class cmdline : private lemon::nocopyable
	{
	public:
		
		cmdline(int args, char ** argv);

		const properties & get_properties() const { return _properties; }

		const std::string & command() const { return _lifecycleOrGoal; }

		const uri::fpath& workspace() const { return _workspace; }

		const uri::fpath& output_directory() const { return _outputDirectory; }

	private:

		void parse_property(const std::string & source);

	private:

		properties						_properties;

		std::string						_lifecycleOrGoal;

		uri::fpath						_workspace;

		uri::fpath						_outputDirectory;
	};

}

#endif //LAKE_CMDLINE_HPP

