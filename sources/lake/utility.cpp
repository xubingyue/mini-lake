#include <lake/utility.hpp>

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

	uri::fpath home()
	{
		uri::fpath result = lake::getenv("MINI_LAKE_HOME");
#ifdef WIN32
		if(result.empty())
		{
			char buffer[MAX_PATH] = {0};

			::GetModuleFileNameA(NULL,buffer,MAX_PATH);

			result = buffer;

			result = result.parent().parent();
		}
#endif

		return result;
	}
}