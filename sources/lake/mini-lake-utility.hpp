/**
* 
* @file     mini-lake-utility
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/11/22
*/
#ifndef MINI_LAKE_UTILITY_HPP
#define MINI_LAKE_UTILITY_HPP

#include <lake/mini-lake.hpp>

namespace lake{

	//////////////////////////////////////////////////////////////////////////

	class nocopyable
	{
	public:

		nocopyable(){}

	private:

		nocopyable(const nocopyable & rhs);

		const nocopyable & operator = (const nocopyable & rhs);
	};

	std::string getenv(const std::string & name);
}

namespace lake{namespace exception{

	struct posix_catalog
	{
		static bool check(int errorCode) { return 0 == errorCode; }

		static std::string error_message(int errorCode);
	};
#ifdef WIN32
	
	struct win32_catalog
	{
		static bool check(DWORD errorCode) { return ERROR_SUCCESS == errorCode; }

		static std::string error_message(DWORD errorCode);
	};

#endif //WIN32

	class error_code : public std::exception
	{
	public:

		error_code(const char * message):std::exception(message){}
		
		virtual const std::string message() const = 0;
	};

	template<typename Code,typename Catalog> 
	class basic_error_code : public error_code
	{
	public:
		typedef Code				error_code_t;

		typedef Catalog				error_code_catalog;
	public:
		
		basic_error_code(const char * message,error_code_t c)
			:error_code(message)
			,_errorCode(c) 
		{}

		error_code_t code() const { return _errorCode; }

		const std::string message() const
		{
			std::stringstream stream;

			stream << what() << std::endl;

			stream << "\t" << error_code_catalog::error_message(code());

			return stream.str();
		}

	private:

		std::string				_message;

		error_code_t			_errorCode;
	};

	template<typename Code,typename Catalog> inline void check_throw(const char * message,Code code)
	{
		if(!Catalog::check(code))
		{
			throw basic_error_code<Code,Catalog>(code);
		}
	}

}}

#endif //MINI_LAKE_UTILITY_HPP

