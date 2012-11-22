/**
 * this file is auto generate by lua script,do not modify it
 * @file     basic_function.hpp
 * @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2012/01/14
 */
#ifndef LEMON_CXX_FUNCTION_FUNCTION_TYPE_HPP
#define LEMON_CXX_FUNCTION_FUNCTION_TYPE_HPP

namespace lemon{

  template<class Signature> class function_type;

  template<typename R>
    struct function_type<R()>
    {
      typedef R result_type;

      typedef function_type<R()> self_type;

      virtual ~function_type(){}

      virtual result_type call() const  = 0; 

      virtual self_type * clone() const = 0;
    };

  
    template<typename R ,typename A0>
    struct function_type<R(A0)>
    {
      typedef R result_type;

      typedef function_type<R(A0)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1>
    struct function_type<R(A0 ,A1)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2>
    struct function_type<R(A0 ,A1 ,A2)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3>
    struct function_type<R(A0 ,A1 ,A2 ,A3)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4>
    struct function_type<R(A0 ,A1 ,A2 ,A3 ,A4)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3,A4) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5>
    struct function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3,A4,A5) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6>
    struct function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3,A4,A5,A6) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7>
    struct function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3,A4,A5,A6,A7) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
    template<typename R ,typename A0 ,typename A1 ,typename A2 ,typename A3 ,typename A4 ,typename A5 ,typename A6 ,typename A7 ,typename A8>
    struct function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)>
    {
      typedef R result_type;

      typedef function_type<R(A0 ,A1 ,A2 ,A3 ,A4 ,A5 ,A6 ,A7 ,A8)> self_type;

      virtual ~function_type(){}

      virtual result_type call(A0,A1,A2,A3,A4,A5,A6,A7,A8) const  = 0; 

      virtual self_type * clone() const = 0;
    };
  
}

#endif //LEMON_CXX_FUNCTION_FUNCTION_TYPE_HPP
