/**
* 
* @file     result_args
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/24
*/
#ifndef LEMONXX_LUABIND_RESULT_ARGS_HPP
#define LEMONXX_LUABIND_RESULT_ARGS_HPP
#include <lemonxx/mpl/inttypes.hpp>
#include <lemonxx/mpl/algorithm.hpp>
#include <lemonxx/utility/utility.hpp>
#include <lemonxx/type_traits/type_traits.hpp>

namespace lemon{namespace luabind{

	template<typename T> struct result_args : mpl::size_t_<1> {};

	template<> struct result_args<void> : mpl::size_t_<0> {};

	template<typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
	struct result_args<tuple<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8> >
		:mpl::size_t_<mpl::size<typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type>::value>
	{

	};

}}
#endif //LEMONXX_LUABIND_RESULT_ARGS_HPP