/**
* 
* @file     mini-lake-fs
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/29
*/
#ifndef MINI_LAKE_FS_HPP
#define MINI_LAKE_FS_HPP

#include <lake/mini-lake-config.hpp>
#include <lake/mini-lake-utility.hpp>


namespace lake{namespace fs{

	//////////////////////////////////////////////////////////////////////////


	class path
	{
	public:

		typedef std::list<std::string>				nodes_type;

		typedef nodes_type::iterator				iterator;

		typedef nodes_type::const_iterator			const_iterator;

		path() {}

		path(const std::string & source);

		template<typename Iterator>
		path(Iterator begin,Iterator end) :_nodes(begin,end) {}

		template<typename Iterator>
		path(const std::string & root,Iterator begin,Iterator end) :_root(root),_nodes(begin,end) {}

		const std::string & root() const { return _root; }

		void root(const std::string & val) {_root = val;}

		const std::string leaf() const 
		{
			if(has_leaf()) return _nodes.back();

			return std::string();
		}

		void leaf(const std::string & val)
		{
			assert(has_leaf());

			_nodes.back() = val;
		}

		bool has_leaf() const { return !_nodes.empty(); }

		bool relative_path() const { return _root == (".") || _root == (".."); }

		iterator begin() { return _nodes.begin(); }

		iterator end() { return _nodes.end(); }

		const_iterator begin() const { return _nodes.begin(); }

		const_iterator end() const { return _nodes.end(); }

		std::string native() const;

		std::string string() const
		{
			return tostring(('/'));
		}

		operator std::string () const
		{
			return native();
		}

		void compress();

		path parent() const;

		bool empty() const {return _root.empty() && _nodes.empty(); }

		path operator / (const char * node) const
		{
			path p (*this);

			p._nodes.push_back(node);

			return p;

		}

		path  operator / (const path & rhs) const
		{
			path p (*this);

			p._nodes.insert(p._nodes.end(),rhs.begin(),rhs.end());

			return p;
		}

		bool operator == (const fs::path & rhs) const
		{
			return _root == rhs._root && _nodes ==  rhs._nodes;
		}

	private:

		std::string tostring(char splitchar) const;

	private:

		std::string		_root;

		nodes_type			_nodes;
	};

	std::string extension(const fs::path & source);

	fs::path extension(const fs::path & source, const std::string & ext);

	inline std::string extension(const std::string & source) { return extension(path(source));}

	inline std::string extension(const std::string & source, const std::string & ext) { return extension(path(source),ext);}

	fs::path relative(fs::path lhs,fs::path rhs);

	//////////////////////////////////////////////////////////////////////////

	class directory_iterator_t 
		: public ::lemon::iterator_t<directory_iterator_t,const std::string,ptrdiff_t>
		, private nocopyable
	{
	public:

		typedef const std::string							value_type;

		typedef value_type									&reference_type;

		typedef value_type									*pointer_type;

		directory_iterator_t();

		directory_iterator_t(const std::string &path);

		~directory_iterator_t();

		void increment();

		pointer_type ptr() const;

		reference_type & dereference() const;

		bool equal(const directory_iterator_t & rhs) const;

	private:

		void close();

	private:

		const std::string								_path;

		std::string										_current;

#ifdef WIN32

		HANDLE											_handle;

		WIN32_FIND_DATAA								_findData;
#else
		DIR												*_dir;

		dirent											*_dirEntry;

#endif //WIN32
	};

	//////////////////////////////////////////////////////////////////////////
	//free functions

	std::string current_directory();

	void current_directory(const std::string& current);

	void remove_directory(const std::string& dir);

	void create_directory(const std::string& dir);

	bool is_directory(const std::string & dir);

	bool exists(const std::string & current);

	void remove_file(const std::string & file);

	void copy(const std::string & source,const std::string & target);

	void move(const std::string & source,const std::string & target);

	bool is_empty(const std::string& dir);

	void remove_directories(const std::string & dir);

	void create_directories(const fs::path & target);

	inline void create_directories(const std::string& current)
	{
		create_directories(fs::path(current));
	}
}}

//////////////////////////////////////////////////////////////////////////



#endif //MINI_LAKE_FS_HPP

