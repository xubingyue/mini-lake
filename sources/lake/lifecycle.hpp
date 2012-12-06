/**
* 
* @file     lifecycle
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/06
*/
#ifndef LAKE_LIFECYCLE_HPP
#define LAKE_LIFECYCLE_HPP
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{namespace lifecycle{

	enum condition 
	{ 
		succeeded = 0x01, failed = 0x02, concurrent = 0x04
	};

	class activity_transition;

	class activity_state : private lemon::nocopyable
	{
	public:
		activity_state();
	};

	class activity_diagram : private lemon::nocopyable
	{
	public:
		activity_diagram();

		~activity_diagram();
	};
}}

#endif //LAKE_LIFECYCLE_HPP

