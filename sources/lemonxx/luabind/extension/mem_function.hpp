/**
* 
* @file     mem_function
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/25
*/
#ifndef LEMONXX_LUABIND_MEM_FUNCTION_HPP
#define LEMONXX_LUABIND_MEM_FUNCTION_HPP
#include <map>
#include <cassert>
#include <lemonxx/luabind/lua_cast.hpp>
#include <lemonxx/luabind/extension/mem_function_table.hpp>

namespace lemon{namespace luabind{

	template<typename Signature> struct classfunction;

	template<typename Class,typename R> 
	struct classfunction<R(Class::*)()> : public mem_handle
	{
		typedef										R(Class::*raw_type)();

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			R r = (obj->*_ptr)();

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			(obj->*_ptr)();

			return 0;
		}
	};

	/*template<typename Class> 
	struct classfunction<void(Class::*)()> : public mem_handle
	{
		typedef										void(Class::*raw_type)();

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			(obj->*_ptr)();

			return 0;
		}
	};*/

	
	template<typename Class,typename R ,typename A0> 
	struct classfunction<R(Class::*)(A0)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-0 - 1 + 0 );

			

			R r = (obj->*_ptr)(a0);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-0 - 1 + 0 );

			

			(obj->*_ptr)(a0);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1> 
	struct classfunction<R(Class::*)(A0 ,A1)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-1 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-1 - 1 + 1 );

			

			R r = (obj->*_ptr)(a0 ,a1);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-1 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-1 - 1 + 1 );

			

			(obj->*_ptr)(a0 ,a1);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-2 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-2 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-2 - 1 + 2 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-2 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-2 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-2 - 1 + 2 );

			

			(obj->*_ptr)(a0 ,a1 ,a2);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-3 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-3 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-3 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-3 - 1 + 3 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-3 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-3 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-3 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-3 - 1 + 3 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3 ,A4);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-4 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-4 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-4 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-4 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-4 - 1 + 4 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-4 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-4 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-4 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-4 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-4 - 1 + 4 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-5 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-5 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-5 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-5 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-5 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-5 - 1 + 5 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-5 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-5 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-5 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-5 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-5 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-5 - 1 + 5 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-6 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-6 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-6 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-6 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-6 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-6 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-6 - 1 + 6 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-6 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-6 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-6 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-6 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-6 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-6 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-6 - 1 + 6 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-7 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-7 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-7 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-7 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-7 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-7 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-7 - 1 + 6 );

			

			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-7 - 1 + 7 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-7 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-7 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-7 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-7 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-7 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-7 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-7 - 1 + 6 );

			

			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-7 - 1 + 7 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);

			return 0;
		}
	};
	
	template<typename Class,typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8> 
	struct classfunction<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> : public mem_handle
	{
		typedef										R(Class::*raw_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8);

		raw_type									_ptr;

		classfunction(const char * name,raw_type ptr)
			:mem_handle(name),_ptr(ptr)
		{}

		int call(lua_State * L) 
		{
			return call(L,typename is_same<void,R>::type());
		}

		int call(lua_State * L,mpl::false_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-8 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-8 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-8 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-8 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-8 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-8 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-8 - 1 + 6 );

			

			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-8 - 1 + 7 );

			

			typedef typename remove_cv<typename remove_reference< A8 >::type>::type B8;

			B8 a8 = lua_cast<B8>::from(L,-8 - 1 + 8 );

			

			R r = (obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);

			lua_cast<result_type>::to(L,r);

			return result_args<result_type>::value;
		}

		int call(lua_State * L,mpl::true_type)
		{
			typedef typename remove_cv<typename remove_reference<R>::type>::type result_type;

			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			Class* obj = (Class*)lua_touserdata(L,lua_upvalueindex(1));

			

			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-8 - 1 + 0 );

			

			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-8 - 1 + 1 );

			

			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-8 - 1 + 2 );

			

			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-8 - 1 + 3 );

			

			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-8 - 1 + 4 );

			

			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-8 - 1 + 5 );

			

			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-8 - 1 + 6 );

			

			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-8 - 1 + 7 );

			

			typedef typename remove_cv<typename remove_reference< A8 >::type>::type B8;

			B8 a8 = lua_cast<B8>::from(L,-8 - 1 + 8 );

			

			(obj->*_ptr)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);

			return 0;
		}
	};
	
}}
#endif //LEMONXX_LUABIND_MEM_FUNCTION_HPP