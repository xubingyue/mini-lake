/**
* 
* @file     uri
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/03
*/
#ifndef LAKE_URI_HPP
#define LAKE_URI_HPP

#include <vector>
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{namespace uri{

	class fpath 
	{
	public:
		typedef std::vector<std::string>						nodes_t;

		typedef nodes_t::iterator								iterator;

		typedef nodes_t::const_iterator							const_iterator;

		fpath(){}
		
		fpath(const char * path) { parse(path); }

		fpath(const std::string &path) { parse(path); }

		template<typename Iterator>
		fpath(Iterator begin, Iterator end) { _nodes.assign(begin,end); }

		template<typename Iterator>
		fpath(const std::string root,Iterator begin, Iterator end) :_root(root)
		{
			_nodes.assign(begin,end);
		}

	public:

		bool empty() const;

		void compress();

		bool relative() const;

		void root(const std::string & val) { _root = val; }

		const std::string & root() const { return _root; }

		std::string leaf() const 
		{
			if(has_leaf()) return _nodes.back();

			return "";
		}

		bool has_leaf() const { return !_nodes.empty(); }

		std::string tostring(char split) const;

		std::string tostring() const{ return tostring('/'); }

		std::string native() const;

		std::string uri() const;

		fpath parent() const
		{
			if(empty()) return fpath();

			else
			{
				if(_nodes.empty()) return fpath(_root);

				return fpath(_root,_nodes.begin(),-- _nodes.end());
			}
		}
	public:

		iterator begin() { return _nodes.begin(); }

		iterator end() { return _nodes.end(); }

		const_iterator begin() const { return _nodes.begin(); }

		const_iterator end() const { return _nodes.end(); }

	public:

		fpath operator / (const char * node) const
		{
			fpath path(*this);

			path._nodes.push_back(node);

			return path;
		}

		fpath operator / (const fpath & rhs) const
		{
			fpath path(*this);

			path._nodes.insert(path._nodes.end(),rhs.begin(),rhs.end());

			return path;
		}

		operator std::string () const { return native(); }

		bool operator == (const fpath & rhs) const
		{
			return _root == rhs._root && _nodes ==  rhs._nodes;
		}

	private:

		void parse(const std::string & path);

	private:

		std::string												_matchine;

		std::string												_root;

		nodes_t													_nodes;
	};

	std::string extension(const fpath & source);

	inline std::string extension(const std::string & source)
	{
		return extension(fpath(source));
	}

	fpath relative(fpath lhs, fpath rhs);
}}

#endif //LAKE_URI_HPP

