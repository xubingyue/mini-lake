/**
* 
* @file     mini-lake-utility
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_UTILITY_HPP
#define MINI_LAKE_UTILITY_HPP

#include <string>
#include <sstream>
#include <lake/uri.hpp>
#include <lake/configure.h>
#include <lake/error_info.hpp>
namespace lake{

	std::string getenv(const std::string & name);

	uri::fpath home();

	template<typename Target,typename Source>
	inline Target lexical_cast(Source source)
	{
		Target target;

		std::stringstream stream;

		stream << source;

		stream >> target;

		if(stream.bad()) throw std::runtime_error("bad lexical_cast!!!");

		return target;
	}
}

#endif //