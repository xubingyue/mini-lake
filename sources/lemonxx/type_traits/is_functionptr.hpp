#ifndef LEMON_STDEXT_IS_FUNCTIONPTR_HPP
#define LEMON_STDEXT_IS_FUNCTIONPTR_HPP
#include <lemonxx/mpl/inttypes.hpp>

namespace lemon{

	template<class T>
	struct _is_funptr
		:public lemon::mpl::false_type
	{
	 
	};
	
	template<class T>
	struct is_function
		:public lemon::mpl::false_type
	{
	 
	};
	
	template<class T>
	struct _is_memfunptr
		:public lemon::mpl::false_type
	{
		
	};
	
	
	template<class R>
	struct _is_funptr<R(*)()>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R>
	struct _is_funptr<R(*)(...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R>
	struct is_function<R()>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R>
	struct is_function<R(...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)()>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)(...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class >
	struct _is_memfunptr<R(Class::*)() const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class >
	struct _is_memfunptr<R(Class::*)(...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)() volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)(...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)() const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class>
	struct _is_memfunptr<R(Class::*)(...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
}

namespace lemon{
	
	template<class R ,typename A0>
	struct _is_funptr<R(*)(A0)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0>
	struct _is_funptr<R(*)(A0,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0>
	struct is_function<R(A0)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0>
	struct is_function<R(A0,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0>
	struct _is_memfunptr<R(Class::*)(A0,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1>
	struct _is_funptr<R(*)(A0 ,A1)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1>
	struct _is_funptr<R(*)(A0 ,A1,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1>
	struct is_function<R(A0 ,A1)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1>
	struct is_function<R(A0 ,A1,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1>
	struct _is_memfunptr<R(Class::*)(A0 ,A1,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2>
	struct _is_funptr<R(*)(A0 ,A1 ,A2)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2>
	struct _is_funptr<R(*)(A0 ,A1 ,A2,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2>
	struct is_function<R(A0 ,A1 ,A2)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2>
	struct is_function<R(A0 ,A1 ,A2,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3>
	struct is_function<R(A0 ,A1 ,A2 ,A3)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3>
	struct is_function<R(A0 ,A1 ,A2 ,A3,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_funptr<R(*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct is_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...)>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...) const>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...) volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
	template<class R,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8) const volatile>
	:public lemon::mpl::true_type
	{
		 
	};
	
	template<class R ,class Class ,typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8>
	struct _is_memfunptr<R(Class::*)(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8,...) const volatile>
	:public lemon::mpl::true_type
	{
		
	};
	
}

#endif //LEMON_STDEXT_IS_FUNCTIONPTR_HPP