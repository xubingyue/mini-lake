/**
* 
* @file     luacall
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/24
*/
#ifndef LEMONXX_LUABIND_LUACALL_HPP
#define LEMONXX_LUABIND_LUACALL_HPP
#include <stdexcept>
#include <lemonxx/luabind/luapi.hpp>
#include <lemonxx/luabind/lua_cast.hpp>
#include <lemonxx/luabind/result_args.hpp>
#include <lemonxx/luabind/lua_tuple_cast.hpp>

namespace lemon{namespace luabind{

	inline void __call(lua_State *L, const char * name,int nargs, int nresults)
	{
		if(!lua_isfunction(L,-1 - nargs))
		{
			std::stringstream stream;

			stream << "expect function(" << name << ") ,got " << lua_typename(L,-1);

			throw std::runtime_error(stream.str().c_str());
		}

		int c = lua_pcall(L,nargs,nresults,0);

		if(c != LUA_OK)
		{
			if(c == LUA_ERRRUN || c == LUA_ERRGCMM) throw std::runtime_error(lua_tostring(L,-1));
		}
	}

	template<typename R>
	inline R call(lua_State *L,const char * name)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		__call(L,name,0,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}

	
	template<typename R ,typename A0>
	inline R call(lua_State *L,const char * name ,A0 a0)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		__call(L,name,0 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		__call(L,name,1 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		__call(L,name,2 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		__call(L,name,3 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		lua_cast<typename remove_cv< A4 >::type>::to(L,a4);
		
		__call(L,name,4 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		lua_cast<typename remove_cv< A4 >::type>::to(L,a4);
		
		lua_cast<typename remove_cv< A5 >::type>::to(L,a5);
		
		__call(L,name,5 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		lua_cast<typename remove_cv< A4 >::type>::to(L,a4);
		
		lua_cast<typename remove_cv< A5 >::type>::to(L,a5);
		
		lua_cast<typename remove_cv< A6 >::type>::to(L,a6);
		
		__call(L,name,6 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		lua_cast<typename remove_cv< A4 >::type>::to(L,a4);
		
		lua_cast<typename remove_cv< A5 >::type>::to(L,a5);
		
		lua_cast<typename remove_cv< A6 >::type>::to(L,a6);
		
		lua_cast<typename remove_cv< A7 >::type>::to(L,a7);
		
		__call(L,name,7 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
	inline R call(lua_State *L,const char * name ,A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7 ,A8 a8)
	{
		typedef typename remove_cv<R>::type result_type;

		assert(name && "luacall expects a function name");

		pop_stack stack(L);

		lua_getglobal(L,name);
		
		lua_cast<typename remove_cv< A0 >::type>::to(L,a0);
		
		lua_cast<typename remove_cv< A1 >::type>::to(L,a1);
		
		lua_cast<typename remove_cv< A2 >::type>::to(L,a2);
		
		lua_cast<typename remove_cv< A3 >::type>::to(L,a3);
		
		lua_cast<typename remove_cv< A4 >::type>::to(L,a4);
		
		lua_cast<typename remove_cv< A5 >::type>::to(L,a5);
		
		lua_cast<typename remove_cv< A6 >::type>::to(L,a6);
		
		lua_cast<typename remove_cv< A7 >::type>::to(L,a7);
		
		lua_cast<typename remove_cv< A8 >::type>::to(L,a8);
		
		__call(L,name,8 + 1,result_args<result_type>::value);

		return lua_cast<result_type>::from(L,-1);
	}
	

}}
#endif //LEMONXX_LUABIND_LUACALL_HPP