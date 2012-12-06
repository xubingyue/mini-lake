#include <errno.h>
#include <lake/date_time.hpp>
#include <lake/error_info.hpp>

namespace lake{

	using namespace error_info;

	time_t time_t::now()
	{
#ifdef WIN32
		union{uint64_t time64;FILETIME ftime;} datetime;

		::GetSystemTimeAsFileTime(&datetime.ftime);

		return datetime.time64;
#else
		timeval tv;

		if(0 != gettimeofday(&tv, 0)) Assert<posix_catalog>(errno,"call gettimeofday error");
		
		return tv;
#endif //WIN32
	}

	void time_t::asign(uint64_t val)
	{
		_val = val;
	}

	void time_t::asign(timeval val)
	{
		_val = val.tv_sec * 10000000 + 116444736000000000 + val.tv_usec * 10; 
	}

	void time_t::asign(::time_t seconds, uint32_t microseconds)
	{
		_val = seconds * 10000000 + 116444736000000000 + microseconds * 10; 
	}

	void localtime_t::from_time_t(localtime_t * datetime,lake::time_t source)
	{
		::time_t now = source.seconds();
#ifdef WIN32
		errno_t error = localtime_s(&datetime->_tm,&now);

		if(0 != error) Assert<error_info::posix_catalog>(errno,"call localtime_s exception!!!");
#else
		if(0 == localtime_r(&now,&datetime->_tm)) Assert<error_info::posix_catalog>(errno,"call localtime_s exception!!!");
		
#endif //WIN32

		datetime->_microseconds = source.microseconds();
	}

	lake::time_t localtime_t::to_time_t(localtime_t * datetime)
	{
		return lake::time_t(mktime(&datetime->_tm),datetime->_microseconds);
	}

	void utctime_t::from_time_t(utctime_t * datetime,lake::time_t source)
	{
		::time_t now = source.seconds();
#ifdef WIN32
		errno_t error = gmtime_s(&datetime->_tm,&now);

		if(0 != error) Assert<error_info::posix_catalog>(errno,"call localtime_s exception!!!");
#else
		if(0 == gmtime_r(&now,&datetime->_tm)) Assert<error_info::posix_catalog>(errno,"call localtime_s exception!!!");

		tm local = localtime_t(source).get_tm();

		datetime->_timeZone = (local.tm_yday - datetime->_tm.tm_yday) * 24 + (local.tm_hour - datetime->_tm.tm_hour);

#endif //WIN32

		datetime->_microseconds = source.microseconds();
	}

	lake::time_t utctime_t::to_time_t(utctime_t * datetime)
	{
#ifdef WIN32
		return lake::time_t(_mkgmtime(&datetime->_tm),datetime->_microseconds);
#else
		return lake::time_t(mktime(&datetime->_tm) + 3600 * datetime->_timeZone ,datetime->_microseconds);
#endif
	}
}