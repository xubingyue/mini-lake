#ifndef LEMON_CXX_STDEXT_FUNCTION_BIND_HPP
#define  LEMON_CXX_STDEXT_FUNCTION_BIND_HPP
#include <lemonxx/function/bind_t.hpp>
#include <lemonxx/function/function.hpp>
namespace lemon{

	template
		<
		typename R,typename Class
		>
	inline function<R()> bind(R(Class::*f)(),Class * object)
	{
		return function<R()>(f,object);
	}
	
	template
		<
		typename R,typename Class
		>
	inline function<R()> bind(R(Class::*f)() const,Class * object)
	{
		return function<R()>(f,object);
	}
	
	template
		<
		typename R,typename Class
		>
	inline function<R()> bind(R(Class::*f)() const,const Class * object)
	{
		return function<R()>(f,object);
	}

}

namespace lemon{
		
		template
		<
		typename R
		,typename A0
		,typename B0
		>
		inline bind_t<
		tuple<B0>, 
		R,
		typename mpl::make_list<A0>::type,
		R(*)(A0)
		> bind(R(*f)(A0),B0 b0)
		{
			typedef tuple<B0> stack_type;
			
			typedef typename mpl::make_list<A0>::type args;
			
			typedef R(*function_type)(A0) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1
		,typename B0 ,typename B1
		>
		inline bind_t<
		tuple<B0 ,B1>, 
		R,
		typename mpl::make_list<A0 ,A1>::type,
		R(*)(A0 ,A1)
		> bind(R(*f)(A0 ,A1),B0 b0 ,B1 b1)
		{
			typedef tuple<B0 ,B1> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1>::type args;
			
			typedef R(*function_type)(A0 ,A1) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2
		,typename B0 ,typename B1 ,typename B2
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2>::type,
		R(*)(A0 ,A1 ,A2)
		> bind(R(*f)(A0 ,A1 ,A2),B0 b0 ,B1 b1 ,B2 b2)
		{
			typedef tuple<B0 ,B1 ,B2> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3
		,typename B0 ,typename B1 ,typename B2 ,typename B3
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type,
		R(*)(A0 ,A1 ,A2 ,A3)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type,
		R(*)(A0 ,A1 ,A2 ,A3 ,A4)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3 ,A4),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3 ,A4) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3 ,b4),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type,
		R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type,
		R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type,
		R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7),f);
		};
		
		template
		<
		typename R
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7 ,typename B8
		>
		inline bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type,
		R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)
		> bind(R(*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8),B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7 ,B8 b8)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type args;
			
			typedef R(*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) ;
		
			typedef bind_t<stack_type,R,args,function_type> result_type;
			
			return result_type(stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7 ,b8),f);
		};
		
		
		
		
		template
		<
		typename R,class Class
		,typename A0
		,typename B0
		>
		inline mem_bind_t<
		tuple<B0>, 
		R,
		typename mpl::make_list<A0>::type,
		Class,
		R(Class::*)(A0)
		> bind(R(Class::*f)(A0),Class * object,B0 b0)
		{
			typedef tuple<B0> stack_type;
			
			typedef typename mpl::make_list<A0>::type args;
			
			typedef R(Class::*function_type)(A0) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0
		,typename B0
		>
		inline mem_bind_t<
		tuple<B0>, 
		R,
		typename mpl::make_list<A0>::type,
		Class,
		R(Class::*)(A0) const
		> bind(R(Class::*f)(A0) const,Class * object,B0 b0)
		{
			typedef tuple<B0> stack_type;
			
			typedef typename mpl::make_list<A0>::type args;
			
			typedef R(Class::*function_type)(A0) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0
		,typename B0
		>
		inline mem_bind_t<
		tuple<B0>, 
		R,
		typename mpl::make_list<A0>::type,
		const Class,
		R(Class::*)(A0) const
		> bind(R(Class::*f)(A0) const,const Class * object,B0 b0)
		{
			typedef tuple<B0> stack_type;
			
			typedef typename mpl::make_list<A0>::type args;
			
			typedef R(Class::*function_type)(A0) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1
		,typename B0 ,typename B1
		>
		inline mem_bind_t<
		tuple<B0 ,B1>, 
		R,
		typename mpl::make_list<A0 ,A1>::type,
		Class,
		R(Class::*)(A0 ,A1)
		> bind(R(Class::*f)(A0 ,A1),Class * object,B0 b0 ,B1 b1)
		{
			typedef tuple<B0 ,B1> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1
		,typename B0 ,typename B1
		>
		inline mem_bind_t<
		tuple<B0 ,B1>, 
		R,
		typename mpl::make_list<A0 ,A1>::type,
		Class,
		R(Class::*)(A0 ,A1) const
		> bind(R(Class::*f)(A0 ,A1) const,Class * object,B0 b0 ,B1 b1)
		{
			typedef tuple<B0 ,B1> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1
		,typename B0 ,typename B1
		>
		inline mem_bind_t<
		tuple<B0 ,B1>, 
		R,
		typename mpl::make_list<A0 ,A1>::type,
		const Class,
		R(Class::*)(A0 ,A1) const
		> bind(R(Class::*f)(A0 ,A1) const,const Class * object,B0 b0 ,B1 b1)
		{
			typedef tuple<B0 ,B1> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2
		,typename B0 ,typename B1 ,typename B2
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2)
		> bind(R(Class::*f)(A0 ,A1 ,A2),Class * object,B0 b0 ,B1 b1 ,B2 b2)
		{
			typedef tuple<B0 ,B1 ,B2> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2
		,typename B0 ,typename B1 ,typename B2
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2) const
		> bind(R(Class::*f)(A0 ,A1 ,A2) const,Class * object,B0 b0 ,B1 b1 ,B2 b2)
		{
			typedef tuple<B0 ,B1 ,B2> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2
		,typename B0 ,typename B1 ,typename B2
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2) const
		> bind(R(Class::*f)(A0 ,A1 ,A2) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2)
		{
			typedef tuple<B0 ,B1 ,B2> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3
		,typename B0 ,typename B1 ,typename B2 ,typename B3
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3
		,typename B0 ,typename B1 ,typename B2 ,typename B3
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3
		,typename B0 ,typename B1 ,typename B2 ,typename B3
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7 ,typename B8
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8),Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7 ,B8 b8)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) ;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7 ,b8),f);
		};
		
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7 ,typename B8
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type,
		Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const,Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7 ,B8 b8)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const;
		
			typedef mem_bind_t<stack_type,R,args,Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7 ,b8),f);
		};
		
		template
		<
		typename R,class Class
		,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8
		,typename B0 ,typename B1 ,typename B2 ,typename B3 ,typename B4 ,typename B5 ,typename B6 ,typename B7 ,typename B8
		>
		inline mem_bind_t<
		tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8>, 
		R,
		typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type,
		const Class,
		R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const
		> bind(R(Class::*f)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const,const Class * object,B0 b0 ,B1 b1 ,B2 b2 ,B3 b3 ,B4 b4 ,B5 b5 ,B6 b6 ,B7 b7 ,B8 b8)
		{
			typedef tuple<B0 ,B1 ,B2 ,B3 ,B4 ,B5 ,B6 ,B7 ,B8> stack_type;
			
			typedef typename mpl::make_list<A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8>::type args;
			
			typedef R(Class::*function_type)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const;
		
			typedef mem_bind_t<stack_type,R,args,const Class,function_type> result_type;
			
			return result_type(object,stack_type(b0 ,b1 ,b2 ,b3 ,b4 ,b5 ,b6 ,b7 ,b8),f);
		};
		
}

#endif // LEMON_CXX_STDEXT_FUNCTION_BIND_HPP
