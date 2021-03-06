/**
* 
* @file     lua_tuple_cast
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/07/24
*/

#ifndef LEMONXX_LUABIND_TUPLE_CAST_HPP
#define LEMONXX_LUABIND_TUPLE_CAST_HPP
#include <lemonxx/utility/utility.hpp>

namespace lemon{namespace luabind{

	template<
		typename Tuple,
		size_t Index = 1,
		bool flag = (mpl::size<Tuple>::value == Index)
	> 
	struct tupe_getter;


	template<
		typename Tuple,
		size_t Index = 1,
		bool flag = (mpl::size<Tuple>::value == Index)
	> 
	struct tupe_setter;

	template<typename Tuple,size_t Index,bool flag> 
	struct tupe_setter : public tupe_setter<Tuple,Index + 1>
	{
		typedef Tuple tuple_type;

		typedef mpl::size_t_<Index - 1> current_index;

		typedef typename basic_tuple_cast<typename Tuple::Seq,current_index::value>::origin_type value_type;

		typedef tupe_setter<Tuple,Index + 1> base_type;

		tupe_setter(lua_State * L,tuple_type & result) : base_type(L,result)
		{
			result.set<current_index::value>(lua_cast<value_type>::from(L,-1));

			lua_pop(L,1);
		}
	};

	template<typename Tuple,size_t Index> 
	struct tupe_setter<Tuple,Index,true>
	{
		typedef Tuple tuple_type;

		typedef mpl::size_t_<Index - 1> current_index;

		typedef typename basic_tuple_cast<typename Tuple::Seq,current_index::value>::origin_type value_type;

		tupe_setter(lua_State * L,tuple_type & result)
		{
			result.set<current_index::value>(lua_cast<value_type>::from(L,-1));

			lua_pop(L,1);
		}
	};

	template<size_t Index,bool flag>
	struct tupe_setter<tuple<>,Index,flag>
	{
		tupe_setter(lua_State * ,tuple<> &){}
	};


	///////////////////////////////////////////////////////////////////////

	template<typename Tuple,size_t Index,bool flag> 
	struct tupe_getter : public tupe_getter<Tuple,Index + 1>
	{
		typedef Tuple tuple_type;

		typedef mpl::size<tuple_type> tuple_size;

		typedef mpl::size_t_<tuple_size::value - Index> current_index;

		typedef typename basic_tuple_cast<typename Tuple::Seq,current_index::value>::origin_type value_type;

		typedef tupe_getter<Tuple,Index + 1> base_type;

		tupe_getter(lua_State * L,const tuple_type & result) : base_type(L,result)
		{
			lua_cast<value_type>::to(L,get<current_index::value>(result));
		}
	};

	template<typename Tuple,size_t Index> 
	struct tupe_getter<Tuple,Index,true>
	{
		typedef Tuple tuple_type;

		typedef mpl::size<tuple_type> tuple_size;

		typedef mpl::size_t_<tuple_size::value - Index> current_index;

		typedef typename basic_tuple_cast<typename Tuple::Seq,current_index::value>::origin_type value_type;

		tupe_getter(lua_State * L,const tuple_type & result)
		{
			lua_cast<value_type>::to(L,get<current_index::value>(result));
		}
	};

	template<size_t Index,bool flag>
	struct tupe_getter<tuple<>,Index,flag>
	{
		tupe_getter(lua_State * ,tuple<> &){}
	};


	//////////////////////////////////////////////////////////////////////////////


	template<typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
	struct lua_cast< tuple<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8> >
	{
		typedef tuple<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8> value_type;

		typedef mpl::inttypes_<int,mpl::size<typename value_type::Seq>::value> nresults;

		static value_type from(lua_State * L,int)
		{
			value_type result;

			tupe_setter<value_type>(L,result);

			return result;
		}

		static void to(lua_State * L,const value_type & val)
		{
			tupe_getter<value_type>(L,val);
		}
	};

}}

#endif //LEMONXX_LUABIND_TUPLE_CAST_HPP