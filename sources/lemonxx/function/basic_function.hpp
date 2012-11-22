/**
 * this file is auto generate by lua script,do not modify it
 * @file     basic_function.hpp
 * @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2012/01/14
 */
#ifndef LEMON_CXX_FUNCTION_BASIC_FUNCTION_HPP
#define LEMON_CXX_FUNCTION_BASIC_FUNCTION_HPP
#include <algorithm>
#include <lemonxx/function/function_type.hpp>

namespace lemon{

  template<class Signature> class basic_function;

  template<typename R>
  class basic_function<R()>
  {
  public:
	  typedef function_type<R()> *wrapper_type;

	  typedef basic_function<R()> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }


	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()() const
	  {
		  return _wrapper->call();
	  }

  private:
	  wrapper_type _wrapper;
  };

 
  template<typename R ,typename A0>
  class basic_function<R(A0)>
  {
  public:

	  typedef function_type<R(A0)> *wrapper_type;

	  typedef basic_function<R(A0)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0) const
	  {
		  return _wrapper->call(a0);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1>
  class basic_function<R(A0 ,A1)>
  {
  public:

	  typedef function_type<R(A0 ,A1)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1) const
	  {
		  return _wrapper->call(a0 ,a1);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2>
  class basic_function<R(A0 ,A1 ,A2)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3>
  class basic_function<R(A0 ,A1 ,A2 ,A3)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4>
  class basic_function<R(A0 ,A1 ,A2 ,A3 ,A4)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3 ,A4)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3 ,a4);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5>
  class basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3 ,a4 ,a5);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6>
  class basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7>
  class basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
  template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
  class basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
  {
  public:

	  typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> *wrapper_type;

	  typedef basic_function<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> self_type;

	  explicit basic_function(wrapper_type wrapper):_wrapper(wrapper){}
	  
	  basic_function():_wrapper(0){}

	  basic_function(const basic_function & rhs)
		  :_wrapper(rhs._wrapper->clone())
	  {	  
	  }

	  ~basic_function()
	  {
		  if(!empty()) delete _wrapper;
	  }

	  void swap(basic_function & rhs)
	  {
		  std::swap(_wrapper,rhs._wrapper);
	  }

	  basic_function & operator = (const basic_function & rhs)
	  {
		  basic_function tmp(rhs);

		  swap(tmp);

		  return *this;
	  }

	  wrapper_type release()
	  {
		  wrapper_type empty = 0;

		  std::swap(empty,_wrapper);

		  return empty;
	  }

	  wrapper_type reset(wrapper_type p) 
	  {
		 std::swap(p,_wrapper);

		 return p;
	  }

	  bool empty() const
	  {
		  return _wrapper == 0;
	  }

	  R operator()(A0 a0 ,A1 a1 ,A2 a2 ,A3 a3 ,A4 a4 ,A5 a5 ,A6 a6 ,A7 a7 ,A8 a8) const
	  {
		  return _wrapper->call(a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8);
	  }

  private:
	  wrapper_type _wrapper;
  };
 
 
}

#endif //LEMON_CXX_FUNCTION_BASIC_FUNCTION_HPP
