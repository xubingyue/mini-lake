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

#include <string>
#include <lake/uri.hpp>
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>


namespace lake{namespace fs{

	class directory_iterator_t 
		: public ::lemon::iterator_t<directory_iterator_t,const std::string,ptrdiff_t>
		, private lemon::nocopyable
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

	void create_directories(const uri::fpath & target);

	inline void create_directories(const std::string& current)
	{
		create_directories(uri::fpath(current));
	}

	uri::fpath fullpath(const uri::fpath & source);
}}

//////////////////////////////////////////////////////////////////////////



#endif //MINI_LAKE_FS_HPP
