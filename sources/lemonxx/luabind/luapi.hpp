/**
* 
* @file     luapi
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/20
*/
#ifndef LEMONXX_LUABIND_LUAPI_HPP
#define LEMONXX_LUABIND_LUAPI_HPP
#include <stdexcept>
#include <lemonxx/luabind/stack.hpp>
#include <lemonxx/luabind/lua_cast.hpp>

namespace lemon{namespace luabind{

	inline void dofile(lua_State * L,const char * file)
	{
		if(luaL_dofile(L,file)) throw std::runtime_error(lua_tostring(L,-1));
		
	}

	template<typename T>
	inline void setglobal(lua_State * L ,const char * varname,T t)
	{
		lua_cast<T>::to(L,t);

		lua_setglobal(L,varname);
	}

	inline void dostring(lua_State * L,const char * message)
	{
		if(luaL_dostring(L,message)) throw std::runtime_error(lua_tostring(L,-1));	
	}

	inline void include_path(lua_State *L,const char * path)
	{
		std::ostringstream stream;

		stream << "package.path = package.path .. \";" << path << "/?.lua\"";

		dostring(L,stream.str().c_str());
	}

	inline void include_cpath(lua_State *L,const char * path)
	{
		std::ostringstream stream;

#ifdef WIN32
		stream << "package.cpath = package.cpath .. \";" << path << "/?.dll\"";
#else
		stream << "package.cpath = package.cpath .. \";" << path << "/?.so\"";
#endif //WIN32

		dostring(L,stream.str().c_str());
	}
}}
#endif //LEMONXX_LUABIND_LUAPI_HPP