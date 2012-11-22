/**
 * this file is auto generate by lua script,do not modify it
 * @file     basic_function.hpp
 * @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2012/01/14
 */
#ifndef LEMON_CXX_FUNCTION_MEM_HANDLE_HPP
#define LEMON_CXX_FUNCTION_MEM_HANDLE_HPP
#include <lemonxx/function/function_type.hpp>

namespace lemon{namespace functions{

	template<class Sig,class Class,class Func> class mem_handle;
	
	template<typename R,class Class,class Func>
	class mem_handle<R(),Class,Func> 
		: public function_type<R()>
	{
	public:
		typedef function_type<R()> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call () const {return (_object->*_fn)();}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	
	template<typename R ,typename A0,class Class,class Func>
	class mem_handle<R(A0),Class,Func> 
		: public function_type<R(A0)>
	{
	public:
		typedef function_type<R(A0)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0) const 
		{
			return (_object->*_fn)(a0);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1,class Class,class Func>
	class mem_handle<R(A0 ,A1),Class,Func> 
		: public function_type<R(A0 ,A1)>
	{
	public:
		typedef function_type<R(A0 ,A1)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1) const 
		{
			return (_object->*_fn)(a0 ,a1);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3 ,A4),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3 ,a4);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3 ,a4 ,a5);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
	template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8,class Class,class Func>
	class mem_handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8),Class,Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	{
	public:
		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> base_type;

		explicit mem_handle(Class * object,Func fn)
			:_object(object),_fn(fn)
		{
		}

		base_type * clone() const{return new mem_handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7 ,A8 a8) const 
		{
			return (_object->*_fn)(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);
		}

	private:
		Class *_object;
		
		Func  _fn;
	};
	
}}
#endif //LEMON_CXX_FUNCTION_MEM_HANDLE_HPP