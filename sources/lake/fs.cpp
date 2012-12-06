#include <stack>
#include <lake/fs.hpp>
#include <lake/error_info.hpp>

//////////////////////////////////////////////////////////////////////////

namespace lake{namespace fs{

	using namespace error_info;

	directory_iterator_t::directory_iterator_t()
#ifdef WIN32
		:_handle(INVALID_HANDLE_VALUE)
#else
		:_dir(0)
#endif 
	{

	}

	directory_iterator_t::directory_iterator_t(const std::string &path) 
#ifdef WIN32
		:_path(path + "\\*"),_handle(INVALID_HANDLE_VALUE)
#else
		:_path(path),_dir(0)
#endif 
	{
		increment();
	}

	directory_iterator_t::~directory_iterator_t()
	{
		close();
	}

	void directory_iterator_t::close()
	{
#ifdef WIN32
		if(_handle != INVALID_HANDLE_VALUE) { ::FindClose(_handle); _handle = INVALID_HANDLE_VALUE;}
#else
		if(0 != _dir) { closedir(_dir); _dir = 0; }
#endif 
	}

	void directory_iterator_t::increment()
	{

#ifdef WIN32
		if(_handle == INVALID_HANDLE_VALUE)
		{

			_handle = ::FindFirstFileA(_path.c_str(),&_findData);

			if(INVALID_HANDLE_VALUE == _handle)
			{
				if(ERROR_FILE_NOT_FOUND == GetLastError()) return;

				Assert<win32_catalog>(GetLastError(),"call FindFirstFileA error!!");
			}

		}
		else
		{

			if(!::FindNextFileA(_handle,&_findData))
			{

				DWORD lastErrorCode = GetLastError();

				if(ERROR_NO_MORE_FILES != lastErrorCode) Assert<win32_catalog>(GetLastError(),"call FindNextFileA error!!");

				_current.clear();

				close();

				return;
			}

		}

		_current = _findData.cFileName;
#else
		if(0 == _dir)
		{

			_dir = opendir(_path.c_str());

			if(0 == _dir) Assert<posix_catalog>(errno,"call opendir error!!!");
		}

		_dirEntry = readdir(_dir);

		if(0 != _dirEntry) _current = _dir->d_name;

		else { _current.clear(); close(); }

#endif //!WIN32
	}

	directory_iterator_t::pointer_type directory_iterator_t::ptr() const
	{
		return &_current;
	}

	directory_iterator_t::reference_type & directory_iterator_t::dereference() const
	{
		return _current;
	}

	bool directory_iterator_t::equal(const directory_iterator_t & rhs) const
	{
#ifdef WIN32
		return rhs._handle == _handle;
#else
		return rhs._dir == _dir;
#endif //WIN32
	}
#ifdef WIN32

	std::string current_directory()
	{
		char buffer[MAX_PATH];

		DWORD length = ::GetCurrentDirectoryA(MAX_PATH,buffer);

		if(0 == length) Assert<win32_catalog>(GetLastError(),"call GetCurrentDirectoryA error");

		return buffer;
	}

	void current_directory(const std::string& current)
	{
		if(!::SetCurrentDirectoryA(current.c_str()))
		{
			Assert<win32_catalog>(GetLastError(),"call SetCurrentDirectoryA error");
		}
	}


	void remove_directory(const std::string& dir)
	{
		if(!::RemoveDirectoryA(dir.c_str()))  
		{  
			Assert<win32_catalog>(GetLastError(),"call RemoveDirectoryA error");
		} 
	}


	void create_directory(const std::string& dir)
	{
		if(!::CreateDirectoryA(dir.c_str(),NULL))
		{  
			Assert<win32_catalog>(GetLastError(),"call CreateDirectoryA error");
		} 
	}


	bool is_directory(const std::string & dir)
	{
		DWORD attributes = ::GetFileAttributesA(dir.c_str());

		if(INVALID_FILE_ATTRIBUTES == attributes) return false;

		return ((FILE_ATTRIBUTE_DIRECTORY & attributes) == FILE_ATTRIBUTE_DIRECTORY)?true:false;
	}


	bool exists(const std::string & current)
	{
		DWORD attributes = ::GetFileAttributesA(current.c_str());

		return (INVALID_FILE_ATTRIBUTES != attributes)?true:false;
	}


	void remove_file(const std::string & file)
	{
		if(!::DeleteFileA(file.c_str()))
		{
			Assert<win32_catalog>(GetLastError(),"call DeleteFileA error");
		}
	}


	void copy(const std::string & source,const std::string & target)
	{
		if(!::CopyFileA(source.c_str(),target.c_str(),TRUE))
		{
			Assert<win32_catalog>(GetLastError(),"call CopyFileA error");
		}
	}


	void move(const std::string & source,const std::string & target)
	{
		if(!::MoveFileA(source.c_str(),target.c_str()))
		{
			Assert<win32_catalog>(GetLastError(),"call MoveFileA error");
		}
	}
#else
	std::string current_directory()
	{
		char buffer[1024] = {0};

		const char *result = getcwd(buffer,sizeof(buffer));

		if(NULL == result) Assert<posix_catalog>(errno,"call getcwd error");

		return buffer;
	}

	void current_directory(const std::string& current)
	{
		if(chdir(current.c_str()) != 0)
		{
			Assert<posix_catalog>(errno,"call chdir error");
		}
	}


	void remove_directory(const std::string& dir)
	{
		if(rmdir(dir.c_str()) != 0)
		{
			Assert<posix_catalog>(errno,"call chdir error");
		}
	}


	void create_directory(const std::string& dir)
	{
		if(mkdir(dir.c_str(),0777) != 0)
		{
			Assert<posix_catalog>(errno,"call mkdir error");
		}
	}


	bool is_directory(const std::string & dir)
	{
		struct stat st;

		if(0 != lstat(dir.c_str(),&st))
		{
			if(ENOENT != errno) Assert<posix_catalog>(errno,"call lstat error");

			return false;
		}

		return S_ISDIR(st.st_mode)?true:false;
	}


	bool exists(const std::string & current)
	{
		if(0 != access(current.c_str(),0))
		{
			if(ENOENT != errno) Assert<posix_catalog>(errno,"call access error");

			return false;
		}

		return true;
	}


	void remove_file(const std::string & file)
	{
		if(0 != unlink(file.c_str()))
		{
			Assert<posix_catalog>(errno,"call unlink error");
		}
	}


	void copy(const std::string & source,const std::string & target)
	{
		if(0 != link(source.c_str(),target.c_str()))
		{
			Assert<posix_catalog>(errno,"call link error");
		}
	}


	void move(const std::string & source,const std::string & target)
	{
		if(0 != rename(source.c_str(),target.c_str()))
		{
			Assert<posix_catalog>(errno,"call link error");
		}
	}
#endif //!WIN32


	bool is_empty(const std::string& dir)
	{
		directory_iterator_t iter(dir.c_str()),end;

		for(;iter != end; ++ iter)
		{
			if("." == *iter) continue;

			if(".." == *iter) continue;

			return false;
		}

		return true;
	}


	void remove_directories(const std::string & dir)
	{
		std::stack<std::string> directories;

		directories.push(dir);

		while(!directories.empty())
		{
			std::string	current = directories.top();

			if(is_empty(current))
			{
				remove_directory(current);

				directories.pop();

				continue;
			}

			directory_iterator_t iter(current),end;

			for(;iter != end; ++ iter)
			{
				if("." == *iter) continue;

				if(".." == *iter) continue;

				std::string path = current + "/" + *iter;

				if(is_directory(path))
				{
					if(is_empty(path)) remove_directory(path);

					else directories.push(path);
				}
				else
				{
					remove_file(path);
				}
			}
		}
	}

	void create_directories(const uri::fpath & target)
	{
		std::stack<uri::fpath> stack;

		uri::fpath::const_iterator iter,end = target.end();

		for(iter = target.begin(); iter != end; ++ iter)
		{
			uri::fpath current(target.root(),target.begin(),iter);

			if(!fs::exists(current.native()))
			{
				fs::create_directory(current.native());
			}
		}

		uri::fpath current(target.root(),target.begin(),end);

		if(!fs::exists(current.native()))
		{
			fs::create_directory(current.native());
		}
	}

	 uri::fpath fullpath(const uri::fpath & source)
	{
		if(!source.relative()) return source;

		return uri::fpath(current_directory()) / source;
	}
}}