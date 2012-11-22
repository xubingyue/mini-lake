/**
* 
* @file     extension-function
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/24
*/
#ifndef LEMONXX_LUABIND_EXTENSION_FUNCTION_HPP
#define LEMONXX_LUABIND_EXTENSION_FUNCTION_HPP
#include <cassert>
#include <lemonxx/luabind/lua_cast.hpp>
#include <lemonxx/luabind/extension.hpp>
#include <lemonxx/luabind/result_args.hpp>
#include <lemonxx/type_traits/type_traits.hpp>

namespace lemon{namespace luabind{

	template<typename Signature	> struct cfunction;


	template<typename R> struct cfunction<R(*)()>
	{
		typedef							R(*sig_type)();

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,R(*ptr)()):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State *,R(*ptr)(),mpl::true_type)
		{
			ptr();

			return 0;
		}

		static int __function_call(lua_State *,R(*ptr)(),mpl::false_type)
		{
			R r = ptr();

			lua_cast<R>::to(r);

			return result_args<R>::value;
		}
	};

	
	template<typename R ,typename A0> struct cfunction<R(*)(A0)>
	{
		typedef							R(*sig_type)(A0);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-0 - 1 + 0 );
			

			ptr(a0);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-0 - 1 + 0);
			

			R r = ptr(a0);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1> struct cfunction<R(*)(A0 ,A1)>
	{
		typedef							R(*sig_type)(A0 ,A1);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-1 - 1 + 0 );
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-1 - 1 + 1 );
			

			ptr(a0 ,a1);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-1 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-1 - 1 + 1);
			

			R r = ptr(a0 ,a1);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2> struct cfunction<R(*)(A0 ,A1 ,A2)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-2 - 1 + 0 );
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-2 - 1 + 1 );
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-2 - 1 + 2 );
			

			ptr(a0 ,a1 ,a2);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-2 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-2 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-2 - 1 + 2);
			

			R r = ptr(a0 ,a1 ,a2);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-3 - 1 + 0 );
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-3 - 1 + 1 );
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-3 - 1 + 2 );
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-3 - 1 + 3 );
			

			ptr(a0 ,a1 ,a2 ,a3);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-3 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-3 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-3 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-3 - 1 + 3);
			

			R r = ptr(a0 ,a1 ,a2 ,a3);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3 ,A4)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3 ,A4);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
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
			

			ptr(a0 ,a1 ,a2 ,a3 ,a4);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-4 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-4 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-4 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-4 - 1 + 3);
			
			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-4 - 1 + 4);
			

			R r = ptr(a0 ,a1 ,a2 ,a3 ,a4);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
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
			

			ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-5 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-5 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-5 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-5 - 1 + 3);
			
			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-5 - 1 + 4);
			
			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-5 - 1 + 5);
			

			R r = ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
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
			

			ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-6 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-6 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-6 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-6 - 1 + 3);
			
			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-6 - 1 + 4);
			
			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-6 - 1 + 5);
			
			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-6 - 1 + 6);
			

			R r = ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
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
			

			ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-7 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-7 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-7 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-7 - 1 + 3);
			
			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-7 - 1 + 4);
			
			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-7 - 1 + 5);
			
			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-7 - 1 + 6);
			
			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-7 - 1 + 7);
			

			R r = ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8> struct cfunction<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	{
		typedef							R(*sig_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8);

		typedef cfunction<sig_type>		self_type;

		std::string						_name;

		sig_type						_ptr;

		cfunction(const char * name,sig_type ptr):_name(name),_ptr(ptr) {}

		void call(module_ & module) const
		{
			struct luaL_Reg reg[] = 
			{
				{_name.c_str(),&self_type::__function},

				{ NULL, NULL }
			};

			lua_pushlightuserdata(module,(void*)_ptr);

			luaL_setfuncs(module,reg,1);
		}

		static int __function(lua_State * L)
		{
			assert(lua_islightuserdata(L,lua_upvalueindex(1)));

			sig_type ptr = (sig_type)lua_touserdata(L,lua_upvalueindex(1));

			return __function_call(L,ptr,typename is_same<void,R>::type());
		}

		static int __function_call(lua_State * L,sig_type ptr,mpl::true_type)
		{
			
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
			

			ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);

			return 0;
		}

		static int __function_call(lua_State *L,sig_type ptr,mpl::false_type)
		{
			
			typedef typename remove_cv<typename remove_reference< A0 >::type>::type B0;

			B0 a0 = lua_cast<B0>::from(L,-8 - 1 + 0);
			
			typedef typename remove_cv<typename remove_reference< A1 >::type>::type B1;

			B1 a1 = lua_cast<B1>::from(L,-8 - 1 + 1);
			
			typedef typename remove_cv<typename remove_reference< A2 >::type>::type B2;

			B2 a2 = lua_cast<B2>::from(L,-8 - 1 + 2);
			
			typedef typename remove_cv<typename remove_reference< A3 >::type>::type B3;

			B3 a3 = lua_cast<B3>::from(L,-8 - 1 + 3);
			
			typedef typename remove_cv<typename remove_reference< A4 >::type>::type B4;

			B4 a4 = lua_cast<B4>::from(L,-8 - 1 + 4);
			
			typedef typename remove_cv<typename remove_reference< A5 >::type>::type B5;

			B5 a5 = lua_cast<B5>::from(L,-8 - 1 + 5);
			
			typedef typename remove_cv<typename remove_reference< A6 >::type>::type B6;

			B6 a6 = lua_cast<B6>::from(L,-8 - 1 + 6);
			
			typedef typename remove_cv<typename remove_reference< A7 >::type>::type B7;

			B7 a7 = lua_cast<B7>::from(L,-8 - 1 + 7);
			
			typedef typename remove_cv<typename remove_reference< A8 >::type>::type B8;

			B8 a8 = lua_cast<B8>::from(L,-8 - 1 + 8);
			

			R r = ptr(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);

			lua_cast<typename remove_cv<typename remove_reference<R>::type>::type>::to(L,r);

			return result_args<R>::value;
		}

	};
	

	template<typename Signature>
	inline cfunction<Signature> def(const char * name, Signature sig)
	{
		return cfunction<Signature>(name,sig);
	}
}}

#endif //LEMONXX_LUABIND_EXTENSION_FUNCTION_HPP