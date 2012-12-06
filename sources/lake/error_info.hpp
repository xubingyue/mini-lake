/**
* 
* @file     error_info
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/01
*/
#ifndef LAKE_ERROR_INFO_HPP
#define LAKE_ERROR_INFO_HPP
#include <sstream>
#include <stdexcept>
#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{namespace error_info{

	struct posix_catalog
	{
		static bool Succeeded(int errorCode){ return 0 == errorCode; }

		static std::string ToString(int errorCode);
	};

#ifdef WIN32

	struct win32_catalog
	{
		static bool Succeeded(DWORD errorCode) { return ERROR_SUCCESS == errorCode; }

		static std::string ToString(DWORD errorCode);
	};

#endif //WIN32
}}

namespace lake{

	struct error_code : public std::runtime_error
	{
		error_code(const char * message):std::runtime_error(message){}

		virtual const std::string message() const = 0;
	};


	template<typename Code,typename Catalog> 
	class error_code_t : public error_code
	{
	public:
		typedef Code				error_code_type;

		typedef Catalog				error_code_catalog;
	public:

		error_code_t(const char * message,error_code_type c)
			:error_code(message)
			,_errorCode(c) 
		{}

		error_code_type code() const { return _errorCode; }

		const std::string message() const
		{
			std::stringstream stream;

			stream << what() << std::endl;

			stream << "\t" << error_code_catalog::ToString(code());

			return stream.str();
		}

	private:

		std::string				_message;

		error_code_type			_errorCode;
	};

	template<typename Catalog,typename Code> inline void Assert(Code code,const char * message)
	{
		if(!Catalog::Succeeded(code))
		{
			throw error_code_t<Code,Catalog>(message,code);
		}
	}
}

#endif //LAKE_ERROR_INFO_HPP
