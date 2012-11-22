#include <lake/mini-lake-utility.hpp>

namespace lake{

	std::string getenv(const std::string & name)
	{
#ifdef WIN32
		size_t result = 0;

		char buffer[1024];

		if(0 != getenv_s(&result,buffer,sizeof(buffer),name.c_str())) return "";

		return buffer;
#else
		char *val = getenv(varname);

		if(NULL == val) return "";

		return val;
#endif //WIN32
	}

}

namespace lake{namespace exception{

	std::string posix_catalog::error_message(int errorCode)
	{
#ifdef WIN32
		char buf[128] = {0};

		strerror_s(buf,errorCode);

		return buf;
#else
		return strerror(errorCode);
#endif //WIN32
	}

#ifdef WIN32

	std::string win32_catalog::error_message(DWORD errorCode)
	{
		LPVOID   lpMsgBuf;  
		
		if(::FormatMessageA(     
			FORMAT_MESSAGE_ALLOCATE_BUFFER   |     
			FORMAT_MESSAGE_FROM_SYSTEM   |     
			FORMAT_MESSAGE_IGNORE_INSERTS,   
			NULL,   
			errorCode,   
			MAKELANGID(LANG_NEUTRAL,   SUBLANG_DEFAULT),   //   Default   language   
			(LPSTR) &lpMsgBuf,   
			0,   
			NULL     
			))
		{
			std::string message = (const char*)lpMsgBuf;

			LocalFree(lpMsgBuf);

			return message;
		}

		return "not found error message!!!!";
	}

#endif //WIN32
}}