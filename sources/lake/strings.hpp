/**
* 
* @file     strings
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/03
*/
#ifndef LAKE_STRINGS_HPP
#define LAKE_STRINGS_HPP

#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{namespace strings{
	template<typename CharType>
	struct to_lowerF
	{
		to_lowerF(const std::locale& Loc ) : _locale(&Loc) {}

		CharType operator ()( CharType Ch ) const
		{
			return std::tolower<CharType>(Ch, *_locale);
		}
	private:
		const std::locale *_locale;
	};

	template<typename CharType>
	struct to_upperF
	{
		to_upperF(const std::locale& Loc ) : _locale(&Loc) {}

		CharType operator ()( CharType Ch ) const
		{
			return std::toupper<CharType>(Ch, *_locale);
		}
	private:
		const std::locale *_locale;
	};
}}

namespace lake{

	template<typename CharType>
	inline std::basic_string<CharType> string_toupper(const CharType* rhs)
	{
		std::locale loc;

		std::basic_string<CharType> result = rhs;

		std::transform(result.begin(),result.end(),result.begin(),string_algorithm::to_upperF<CharType>(loc));

		return result;
	}

	template<typename CharType>
	inline std::basic_string<CharType> string_toupper(const std::basic_string<CharType> & rhs)
	{
		std::locale loc;

		std::basic_string<CharType> result(rhs.begin(),rhs.end());

		std::transform(result.begin(),result.end(),result.begin(),string_algorithm::to_upperF<CharType>(loc));

		return result;
	}

	template<typename CharType>
	inline std::basic_string<CharType> string_tolower(const std::basic_string<CharType> & rhs)
	{
		std::locale loc;

		std::basic_string<CharType> result(rhs.begin(),rhs.end());

		std::transform(result.begin(),result.end(),result.begin(),string_algorithm::to_lowerF<CharType>(loc));

		return result;
	}


	template<typename CharType>
	inline std::basic_string<CharType> string_replaceall
		(
		const std::basic_string<CharType> & source,
		const std::basic_string<CharType> & match,
		const std::basic_string<CharType> & replace
		)
	{
		typename std::basic_string<CharType>::size_type pos;

		std::basic_string<CharType> result = source;

		while(std::basic_string<CharType>::npos != (pos = result.find(match)))
		{
			result.replace(pos,match.size(),replace);
		}

		return result;
	}


	bool string_isspace(const std::string & source)
	{
		std::string::const_iterator iter ,end = source.end();

		for(iter = source.begin(); iter != end; ++ iter)
		{
			if(!isspace(*iter)) return false;
		}

		return true;
	}
}
#endif //LAKE_STRINGS_HPP

