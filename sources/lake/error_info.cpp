#include <lake/error_info.hpp>

namespace lake{namespace error_info{
	std::string posix_catalog::ToString(int errorCode)
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

	std::string win32_catalog::ToString(DWORD errorCode)
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