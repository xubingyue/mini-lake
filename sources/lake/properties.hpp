/**
* 
* @file     properties
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/02
*/
#ifndef LAKE_PROPERTIES_HPP
#define LAKE_PROPERTIES_HPP
#include <map>
#include <string>
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{

	class properties :  private lemon::nocopyable
	{
	public:

		typedef std::multimap<std::string,std::string>		container_type;

	private:

		container_type										_container;
	};

}

#endif //LAKE_PROPERTIES_HPP
