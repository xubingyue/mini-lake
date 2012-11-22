/**
 * 
 * @file     bind_t
 * @brief    Copyright (C) 2010  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2010/12/09
 */
#ifndef LEMON_STDEXT_BIND_BIND_T_HPP
#define LEMON_STDEXT_BIND_BIND_T_HPP
#include <memory>
#include <lemonxx/function/stack.hpp>
#include <lemonxx/function/function_type.hpp>

namespace lemon{
	
	template<class Stack,typename R,typename Args,typename Func> class bind_t;
	
	template<class Stack,typename R,typename Args,class Class,typename Func> class mem_bind_t;
	
	template<class Stack,typename R,typename Args,typename Func> 
	class bind_t 
	{
	public:
		
		typedef Stack 										stack_type;
		
		typedef mpl::size_t_<mpl::size<stack_type>::value> 	stack_size;
		
		typedef R											return_type;
		
		typedef Func										function_type;
		
		typedef Args										args;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,0 >::type P0;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,1 >::type P1;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,2 >::type P2;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,3 >::type P3;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,4 >::type P4;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,5 >::type P5;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,6 >::type P6;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,7 >::type P7;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,8 >::type P8;
		
		bind_t(const stack_type & stack,function_type func):_stack(stack),_func(func){}
		
		inline return_type operator()() const
		{
			return invoke_args(tuple<>(),stack_size());
		}
		
		inline return_type operator()(P0 p0) const
		{
			return invoke_args(tuple<P0>(p0),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1) const
		{
			return invoke_args(tuple<P0 ,P1>(p0 ,p1),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2>(p0 ,p1 ,p2),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3>(p0 ,p1 ,p2 ,p3),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4>(p0 ,p1 ,p2 ,p3 ,p4),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5>(p0 ,p1 ,p2 ,p3 ,p4 ,p5),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6 ,P7 p7) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6 ,P7>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6 ,p7),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6 ,P7 p7 ,P8 p8) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6 ,P7 ,P8>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6 ,p7 ,p8),stack_size());
		}
		
		
	private:
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 0 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 1 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 2 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 3 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 4 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 5 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 6 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 7 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s) ,binds::unwind<args,7 >(_stack,s));
		}
		
		template<typename S> 
		inline return_type invoke_args(const S & s,mpl::size_t_< 8 + 1 >) const
		{
			return _func(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s) ,binds::unwind<args,7 >(_stack,s) ,binds::unwind<args,8 >(_stack,s));
		}
		
	
	private:
		stack_type 		_stack;
		function_type 	_func;
	};
	
	
	template<class Stack,typename R,typename Args,class Class,typename Func>
	class mem_bind_t 
	{
	public:
		
		typedef Stack 										stack_type;
		
		typedef mpl::size_t_<mpl::size<stack_type>::value> 	stack_size;
		
		typedef R											return_type;
		
		typedef Func										function_type;
		
		typedef Args										args;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,0 >::type P0;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,1 >::type P1;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,2 >::type P2;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,3 >::type P3;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,4 >::type P4;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,5 >::type P5;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,6 >::type P6;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,7 >::type P7;
		
		typedef typename binds::call_parameters<typename stack_type::Seq,args,8 >::type P8;
		
		mem_bind_t(Class *object,const stack_type & stack,function_type func):_object(object),_stack(stack),_func(func){}
		
		inline return_type operator()() const
		{
			return invoke_args(tuple<>(),stack_size());
		}
		
		inline return_type operator()(P0 p0) const
		{
			return invoke_args(tuple<P0>(p0),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1) const
		{
			return invoke_args(tuple<P0 ,P1>(p0 ,p1),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2>(p0 ,p1 ,p2),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3>(p0 ,p1 ,p2 ,p3),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4>(p0 ,p1 ,p2 ,p3 ,p4),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5>(p0 ,p1 ,p2 ,p3 ,p4 ,p5),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6 ,P7 p7) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6 ,P7>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6 ,p7),stack_size());
		}
		
		inline return_type operator()(P0 p0 ,P1 p1 ,P2 p2 ,P3 p3 ,P4 p4 ,P5 p5 ,P6 p6 ,P7 p7 ,P8 p8) const
		{
			return invoke_args(tuple<P0 ,P1 ,P2 ,P3 ,P4 ,P5 ,P6 ,P7 ,P8>(p0 ,p1 ,p2 ,p3 ,p4 ,p5 ,p6 ,p7 ,p8),stack_size());
		}
		
		
	private:
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 0 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 1 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 2 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 3 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 4 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 5 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 6 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 7 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s) ,binds::unwind<args,7 >(_stack,s));
		}
		
		template<typename S>
		inline return_type invoke_args(const S & s,mpl::size_t_< 8 + 1 >) const
		{
			return (_object->*_func)(binds::unwind<args,0>(_stack,s) ,binds::unwind<args,1 >(_stack,s) ,binds::unwind<args,2 >(_stack,s) ,binds::unwind<args,3 >(_stack,s) ,binds::unwind<args,4 >(_stack,s) ,binds::unwind<args,5 >(_stack,s) ,binds::unwind<args,6 >(_stack,s) ,binds::unwind<args,7 >(_stack,s) ,binds::unwind<args,8 >(_stack,s));
		}
		
	
	private:
		Class           *_object;
		stack_type 		_stack;
		function_type 	_func;
	};
}
#endif	//LEMON_STDEXT_BIND_BIND_T_HPP
