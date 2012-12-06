/**
* 
* @file     date_time
* @brief    Copyright (C) 2012  yayanyang All Rights Reserved 
* @author   yayanyang
* @version  1.0.0.0  
* @date     2012/12/04
*/
#ifndef LAKE_DATE_TIME_HPP
#define LAKE_DATE_TIME_HPP

#ifdef WIN32
#	include <time.h>
#else
#	include <sys/time.h>
#endif 

#include <lake/configure.h>
#include <lemonxx/utility/utility.hpp>

namespace lake{

	typedef uint64_t time_duration;
	// 64-bit value representing the number of 100-nanosecond intervals 
	// since January 1, 1601 (UTC).
	class time_t
	{
	public:
		static time_t now();
	public:

		time_t(time_duration val) { asign(val); }

		time_t(timeval val) { asign(val); }
		
		time_t(::time_t seconds, uint32_t microseconds) { asign(seconds,microseconds); }

		operator time_duration () const { return _val; }

		const time_t &  operator = (uint64_t val)
		{
			asign(val);

			return *this;
		}

		const time_t &  operator = (timeval val)
		{
			asign(val);

			return *this;
		}

		::time_t seconds() const { return (_val - 116444736000000000) /10000000; }

		uint32_t microseconds() const { return (_val - 116444736000000000) % 10000000 / 10; }

		time_duration operator - (const time_t & rhs) const
		{
			return _val - rhs._val;
		}

		time_t & operator -= (const time_t & rhs)
		{
			_val = (*this - rhs);

			return *this;
		}

		time_t operator + (time_duration rhs) const
		{
			return _val + rhs;
		}

		time_t & operator += (time_duration rhs)
		{
			_val = (_val +  rhs);

			return *this;
		}

		bool operator > (const time_t & rhs) const
		{
			return _val > rhs._val;
		}

		bool operator >= (const time_t & rhs) const
		{
			return _val >= rhs._val;
		}

		bool operator < (const time_t & rhs) const
		{
			return _val < rhs._val;
		}

		bool operator <= (const time_t & rhs) const
		{
			return _val <= rhs._val;
		}

		bool operator == (const time_t & rhs) const
		{
			return _val == rhs._val;
		}

		bool operator != (const time_t & rhs) const
		{
			return _val != rhs._val;
		}

	private:

		void asign(uint64_t val);

		void asign(timeval val);

		void asign(::time_t seconds, uint32_t microseconds);

	private:

		uint64_t											_val;
	};

	template<typename Type>
	class basic_datetime_t 
	{
	public:
		/*basic_datetime_t()
		{
			Type::fromtime(reinterpret_cast<Type*>(this),time_t::now());
		}*/
		basic_datetime_t(lake::time_t source)
		{
			Type::from_time_t(reinterpret_cast<Type*>(this),source);
		}

		lake::time_t time() const
		{
			return Type::to_time_t(reinterpret_cast<Type*>(this));
		}

		tm get_tm() const { return _tm; }

		uint32_t microseconds() const { return _microseconds; }

	protected:

		tm					_tm;

		uint32_t			_microseconds;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @class	localtime_t
	///
	/// @brief	Localtime t. 
	///
	/// @author	Yuki
	/// @date	2012/1/15
	////////////////////////////////////////////////////////////////////////////////////////////////////

	class localtime_t : public basic_datetime_t<localtime_t>
	{
	public:
		/*localtime_t()
			:basic_datetime_t<localtime_t>()
		{}*/

		localtime_t(time_t source)
			:basic_datetime_t<localtime_t>(source)
		{}
	
		static void from_time_t(localtime_t * datetime,lake::time_t source);

		static lake::time_t to_time_t(localtime_t * datetime);
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @class	utctime_t
	///
	/// @brief	Utctime t. 
	///
	/// @author	Yuki
	/// @date	2012/1/15
	////////////////////////////////////////////////////////////////////////////////////////////////////

	class utctime_t : public basic_datetime_t<utctime_t>
	{
	public:
		/*utctime_t()
			:basic_datetime_t<utctime_t>()
		{}*/

		utctime_t(time_t source)
			:basic_datetime_t<utctime_t>(source)
		{}

		static void from_time_t(utctime_t * datetime,lake::time_t source);

		static lake::time_t to_time_t(utctime_t * datetime);
#ifndef WIN32
	private:
		int										_timeZone;
#endif //WIN32
	};
}

#endif //LAKE_DATE_TIME_HPP

