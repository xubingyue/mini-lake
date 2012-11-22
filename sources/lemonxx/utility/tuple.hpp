/**
* 
* @file     basic_tuple
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/01/16
*/
#ifndef LEMON_CXX_UTILITY_TUPLE_HPP
#define LEMON_CXX_UTILITY_TUPLE_HPP

#include<lemonxx/mpl/nulltype.hpp>
#include <lemonxx/utility/basic_tuple.hpp>

namespace lemon{

    template<size_t N,class Tuple>
	inline typename parameter<typename mpl::at<typename Tuple::Seq,N>::type>::type get(const Tuple & tuple)
	{
		return ((const typename basic_tuple_cast<typename Tuple::Seq,N>::type&)tuple).Value;
	}

	template<size_t N,class Tuple>
	inline void set(Tuple &tuple,typename parameter<typename mpl::at<typename Tuple::Seq,N>::type>::type val)
	{
		((typename basic_tuple_cast<typename Tuple::Seq,N>::type&)tuple).Value = val;
	}

	template<typename A0 = mpl::null ,typename A1 = mpl::null ,typename A2 = mpl::null ,typename A3 = mpl::null ,typename A4 = mpl::null ,typename A5 = mpl::null ,typename A6 = mpl::null ,typename A7 = mpl::null ,typename A8 = mpl::null>
	struct tuple
	{
		
		typedef typename parameter< A0 >::type P0;
		
		typedef typename parameter< A1 >::type P1;
		
		typedef typename parameter< A2 >::type P2;
		
		typedef typename parameter< A3 >::type P3;
		
		typedef typename parameter< A4 >::type P4;
		
		typedef typename parameter< A5 >::type P5;
		
		typedef typename parameter< A6 >::type P6;
		
		typedef typename parameter< A7 >::type P7;
		
		typedef typename parameter< A8 >::type P8;
		
		typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type Seq;

		typedef typename mpl::begin<Seq>::type begin;

		typedef typename mpl::end<Seq>::type end;

		typedef basic_tuple<begin,end> base_type;

		base_type Base;
		
		tuple(){}
		
		
		
		tuple(A0 a0)
		{
			
			set< 0 >(a0);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
			set< 4 >(a4);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
			set< 4 >(a4);
			
			set< 5 >(a5);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
			set< 4 >(a4);
			
			set< 5 >(a5);
			
			set< 6 >(a6);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
			set< 4 >(a4);
			
			set< 5 >(a5);
			
			set< 6 >(a6);
			
			set< 7 >(a7);
			
		}
		
		
		
		tuple(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7 ,A8 a8)
		{
			
			set< 0 >(a0);
			
			set< 1 >(a1);
			
			set< 2 >(a2);
			
			set< 3 >(a3);
			
			set< 4 >(a4);
			
			set< 5 >(a5);
			
			set< 6 >(a6);
			
			set< 7 >(a7);
			
			set< 8 >(a8);
			
		}
		
		

		template<size_t N>
		typename parameter<typename mpl::at<Seq,N>::type>::type get() const
		{
			return ((const typename basic_tuple_cast<Seq,N>::type&)*this).Value;
		}

		template<size_t N>
		void set(typename parameter<typename mpl::at<Seq,N>::type>::type val)
		{
			((typename basic_tuple_cast<Seq,N>::type&)*this).Value = val;
		}

		
		inline void swap(tuple & rhs)
		{
			Base.swap(rhs.Base);
		}
		
		inline bool operator == (const tuple & rhs) const
		{
			return Base == rhs.Base;
		}
		
		inline bool operator != (const tuple & rhs) const
		{
			return !(*this == rhs);
		}
	};

	
	namespace mpl{
		template<typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
		struct size<tuple<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8> >
			:mpl::size_t_<size<typename make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type>::value>
		{
		};
	}

}

#endif //LEMON_CXX_UTILITY_TUPLE_HPP
