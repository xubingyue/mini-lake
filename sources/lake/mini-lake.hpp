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
#include <vector>
#include <errno.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <stdexcept>
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
#endif //WIN32

#define LAKE_PLUGIN_PATH									"Plugin.Path"

namespace lake{namespace config{

	const static char * MultiValueProperties[] = 
	{
		LAKE_PLUGIN_PATH,
	};

	const static char * BuildinLifeCycle[] = { "compile","test","package","install" };

}}



#endif //LAKE_MINI_LAKE_HPP

