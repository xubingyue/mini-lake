/**
* 
* @file     properties
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/02
*/
#ifndef LAKE_PROPERTIES_HPP
#define LAKE_PROPERTIES_HPP
#include <map>
#include <string>
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>


namespace lake{

	class properties :  private lemon::nocopyable
	{
	public:

		typedef std::multimap<std::string,std::string>		container_type;

		typedef container_type::iterator					iterator;

		typedef container_type::const_iterator				const_iterator;

		typedef std::pair<const_iterator,const_iterator>	const_range;

		typedef std::pair<iterator,iterator>				range;

	public:

		iterator begin() { return _container.begin(); }

		const_iterator begin() const { return _container.begin(); }

		iterator end() { return _container.end(); }

		const_iterator end() const { return _container.end(); }

	public:

		size_t count(const char * key) { return _container.count(key); }

		void insert(const char * key, const char * val);

		void insert(const std::string & key, const std::string & val)
		{
			insert(key.c_str(),val.c_str());
		}

		range search(const char * key);

		const_range search(const char * key) const;

	private:

		container_type										_container;
	};

}

#endif //LAKE_PROPERTIES_HPP
