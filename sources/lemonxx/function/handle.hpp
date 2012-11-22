/**
 * this file is auto generate by lua script,do not modify it
 * @file     basic_function.hpp
 * @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2012/01/14
 */
#ifndef LEMON_CXX_FUNCTION_HANDLE_HPP
#define LEMON_CXX_FUNCTION_HANDLE_HPP
#include <lemonxx/function/function_type.hpp>
namespace lemon{namespace functions{
    
    template<class Sig,class Func> class handle;
 
    template<typename R,class Func> 
	class handle<R(),Func> : public function_type<R()>
	{
	public:

		typedef function_type<R()> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call () const {return _fn();}

	private:
		Func _fn;
	};
	
    
    template<typename R ,typename A0, class Func> 
	class handle<R(A0),Func> 
		: public function_type<R(A0)>
	{
	public:

		typedef function_type<R(A0)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0) const 
		{
			return _fn(a0);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1, class Func> 
	class handle<R(A0 ,A1),Func> 
		: public function_type<R(A0 ,A1)>
	{
	public:

		typedef function_type<R(A0 ,A1)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1) const 
		{
			return _fn(a0 ,a1);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2, class Func> 
	class handle<R(A0 ,A1 ,A2),Func> 
		: public function_type<R(A0 ,A1 ,A2)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2) const 
		{
			return _fn(a0 ,a1 ,a2);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3 ,A4),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3 ,a4);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3 ,a4 ,a5);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);
		}

	private:
		Func _fn;
	}; 
    
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8, class Func> 
	class handle<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8),Func> 
		: public function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
	{
	public:

		typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> base_type;

		explicit handle(Func fn)
			:_fn(fn)
		{
		}

		base_type * clone() const{return new handle(*this);}

		R call (A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7 ,A8 a8) const 
		{
			return _fn(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);
		}

	private:
		Func _fn;
	}; 
    

	
	
}}

#endif //LEMON_CXX_FUNCTION_HANDLE_HPP
