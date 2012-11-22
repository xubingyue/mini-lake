/**
* 
* @file     mini-lake-ast
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_AST_HPP
#define MINI_LAKE_AST_HPP

#include <lake/mini-lake-utility.hpp>

namespace lake{namespace pom{

	class pom;

	struct visitor;

	class project;

	class package;
}}

namespace lake{namespace pom{

	struct visitor : private nocopyable
	{
		virtual bool visit(project * proj) = 0;
	};
	

	//////////////////////////////////////////////////////////////////////////

	class property
	{
	public:

		property(){}

		explicit property(const std::string & pair);

		explicit  property(const std::string & name, const std::string & val);

		const std::string & name() const { return _name;}

		const std::string & value() const { return _value;}

	private:

		std::string				_name;

		std::string				_value;
	};

	//////////////////////////////////////////////////////////////////////////

	class pom : private nocopyable
	{
	public:
		
		typedef std::multimap<std::string,property> properties_type;

		typedef std::vector<const char*> property_values;

	public:
		/*
		 *@return bool	if override the exist property return true 
		 *				else return false
		 */
		bool set_property(const property & p);
		/*
		 *@return bool	if override the exist property return true 
		 *				else return false
		 */
		bool set_property(const std::string & name, const std::string & val);
		
		property_values get_property(const std::string & name) const;

	public:

		virtual bool accept(visitor *) = 0;

	private:

		properties_type				_properties;
	};

	//////////////////////////////////////////////////////////////////////////

	class project : public pom
	{
	public:
		
		bool accept(visitor * v);
	};
}}
#endif //MINI_LAKE_AST_HPP

