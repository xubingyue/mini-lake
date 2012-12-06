/**
* 
* @file     lake
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/30
*/
#include <stdexcept>
#include <lake/fs.hpp>
#include <lake/trace.hpp>
#include <lake/cmdline.hpp>
#include <lake/utility.hpp>
#include <lake/error_info.hpp>


using namespace lake;

#define LEMON_PACKAGE_NAME									"lemon.xpkg"

int main(int args, char ** argv)
{
	trace::write(trace::debug,"Mini Lake - Lemon Lifecycle Tool Version 1.0.0.0");
	trace::write(trace::debug,"Copyright (C) 2012  yayanyang All Rights Reserved\n");

	try
	{
		cmdline parser(args, argv);

		//get the home path.

		uri::fpath homePath = home();

		if(homePath.empty()) throw std::runtime_error("you must set the MINI_LAKE_HOME environment variable!!!");
		
		trace::write(trace::debug,"The Mini Lake Home Path :%s",homePath.native().c_str());
	}
	catch(const lake::error_code & e)
	{
		trace::write(trace::error,"%s",e.message().c_str());

		return 1;
	}
	catch(const std::runtime_error & e)
	{
		trace::write(trace::error,"%s",e.what());

		return 1;
	}
	
}