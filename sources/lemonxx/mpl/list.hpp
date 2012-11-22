/**
 * this file is auto generate by lua script,do not modify it
 * @file     list.hpp
 * @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
 * @author   yayanyang
 * @version  1.0.0.0  
 * @date     2012/01/14
 */
#ifndef LEMON_CXX_MPL_LIST_HPP
#define LEMON_CXX_MPL_LIST_HPP
#include<lemonxx/mpl/nulltype.hpp>
namespace lemon{namespace mpl{

   template<class Head,class Tail> struct list
   {
      typedef Head head;
      
      typedef Tail tail;
   };

   template<typename T0 = null ,typename T1 = null,typename T2 = null,typename T3 = null,typename T4 = null,typename T5 = null,typename T6 = null,typename T7 = null,typename T8 = null>
   struct make_list;

   template<typename T0 ,typename T1 ,typename T2 ,typename T3 ,typename T4 ,typename T5 ,typename T6 ,typename T7 ,typename T8 >
   struct make_list
   {
     typedef list<T0,typename make_list<T1 ,T2 ,T3 ,T4 ,T5 ,T6 ,T7 ,T8 >::type> type;
   };

   template<>
   struct make_list<null ,null,null,null,null,null,null,null,null>
   {
     typedef list<null,null> type;
   };
   
}}

#endif //LEMON_CXX_MPL_LIST_HPP
