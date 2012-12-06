#include <stdarg.h>
#include <lake/trace.hpp>

#ifndef WIN32
#define printf_s printf
#endif 

namespace lake{namespace trace{

	namespace{

		level  __tracelevel = (level)(text | warning | error | debug);
	}

	void color(level l)
	{
#ifdef WIN32
		HANDLE console = ::GetStdHandle(STD_OUTPUT_HANDLE);

		WORD attribute = 0;

		if(l == error) { attribute = FOREGROUND_RED; }

		if(l == warning ) {  attribute = FOREGROUND_RED | FOREGROUND_GREEN; }

		if(l == debug ) { attribute = FOREGROUND_INTENSITY;}

		if(l == text) {attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;}

		::SetConsoleTextAttribute(console, attribute);

		if(l == error) { printf_s("[Error] "); }

		if(l == warning ) { printf_s("[Warning] "); }

		if(l == debug ) {printf_s("[Debug] "); }

		if(l == text) {printf_s("[Message] "); }
#else
#endif 
	}

	void setlevel(level val) { __tracelevel = val; }

	void write(level l, const char * format, ...)
	{
		if((l & __tracelevel) != l) return;

		va_list args;

		va_start(args, format);

		color(l);

#ifdef WIN32
		vprintf_s(format,args);

		printf_s("\n");
#else
		vprintf(format,args);

		printf("\n");
#endif
	}
}}