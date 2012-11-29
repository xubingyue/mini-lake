/**
* 
* @file     mini-lake
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef LAKE_MINI_LAKE_HPP
#define LAKE_MINI_LAKE_HPP
#include <map>
#include <list>
#include <stack>
#include <vector>
#include <cassert>
#include <errno.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include <lemonxx/utility/utility.hpp>

#ifdef WIN32
#	define WIN32_LEAN_AND_MEAN  
#	include <Windows.h>
#	include <WinSock2.h>
#	include <Ws2tcpip.h>
#	include <tchar.h>
#	pragma comment(lib,"Ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#endif //WIN32

#define LAKE_PLUGIN_PATH									"plugin.path"

#define LAKE_SOURCE_PATH									"source.Path"

#define LAKE_BUILD_PATH										"build.path"

#define LAKE_PLUGIN_SCRIPT_EXTENSION						"lua"

#define LAKE_PLUGIN_ONLOAD_SCRIPT							"onload.lua"

#define LAKE_PLUGIN_SCRIPT_DIR								"lua"

#define LAKE_PLUGIN_RESOURCE_DIR							"resources"

#define LAKE_GLOBAL_SETTING_PLUGIN							"Lemon.Lake.Setting"

#define LAKE_GLOBAL_SETTING_PLUGIN_START_GOAL				"start"

namespace lake{namespace config{

	const static char * MultiValueProperties[] = 
	{
		LAKE_PLUGIN_PATH,
	};

	const static char * BuildinLifeCycle[] = { "compile","test","package","install" };

}}



#endif //LAKE_MINI_LAKE_HPP

