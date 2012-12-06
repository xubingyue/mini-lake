/**
* 
* @file     trace
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/03
*/
#ifndef LAKE_TRACE_HPP
#define LAKE_TRACE_HPP
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{namespace trace{

	enum level{ debug = 0x01 ,text = 0x02 ,warning = 0x04 ,error = 0x08 };

	void setlevel(level val);

	void write(level l,const char * format, ...);
}}

#endif //LAKE_TRACE_HPP

