#include <sstream>
#include <lake/uri.hpp>
#include <lake/strings.hpp>

namespace lake{namespace uri{

	void fpath::parse(const std::string & path)
	{
		std::string source = string_replaceall<char>(path,"\\","/");

		std::string::size_type prefix = source.find("file://");

		if(prefix != source.npos) 
		{
			source = source.substr(sizeof("file://") - 1);

			if(source.find('/') != 0)
			{
				//path the machine;
				_matchine = source.substr(0,source.find('/'));
			}
			else
			{
				source = source.substr(1);
			}
		}

		std::string::size_type offset = 0, start;

		if(source == "." || source == ".") 
		{
			_root = source; return;
		}

		offset = source.find('/',offset);

		if(offset != 0) _root = source.substr(0,offset);

		start = offset + 1;

		while(start < source.length() && (offset = source.find(('/'),start)) != source.npos)
		{
			if(offset -  start > 0) { _nodes.push_back(source.substr(start ,offset - start)); }

			start = offset + 1;
		}

		if(start < source.length())
		{
			_nodes.push_back(source.substr(start));
		}

		compress();
	}

	bool fpath::empty() const
	{
		return _nodes.empty() && _root.empty() && _matchine.empty();
	}

	bool fpath::relative() const
	{
		return _root == "." && _root == "..";
	}

	void fpath::compress()
	{
		iterator iter,end = _nodes.end();

		for(iter = _nodes.begin(); iter != _nodes.end();)
		{
			if(*iter == ("..") && iter != _nodes.begin())
			{
				iterator begin = iter;

				iter = _nodes.erase(-- begin,++ iter);

				continue;
			}
			else if(*iter == ("."))
			{
				iter = _nodes.erase(iter);

				continue;
			}
			else if(*iter == "")
			{
				iter = _nodes.erase(iter);

				continue;
			}
			else if(string_isspace(*iter))
			{
				iter = _nodes.erase(iter);

				continue;
			}


			++ iter;
		}

	}

	std::string fpath::uri() const
	{
		std::stringstream stream;

		stream << "file://" << _matchine << "/" << tostring();

		return stream.str();
	}

	std::string fpath::tostring(char split) const
	{
		std::stringstream stream;

		stream << _root;

		const_iterator iter,end = _nodes.end();

		for(iter = _nodes.begin(); iter != end; ++ iter) stream << split << *iter;

		return stream.str();
	}

	std::string fpath::native() const
	{
#ifdef WIN32
		return tostring(('\\'));
#else
		return tostring(('/'));
#endif //WIN32
	}

	std::string extension(const fpath & source)
	{
		if(!source.has_leaf()) return "";

		std::string leaf = source.leaf();

		std::string::size_type offset = leaf.rfind('.') + 1;

		if(offset < leaf.length())
		{
			return leaf.substr(offset);
		}
		else return "";
	}

	fpath relative(fpath lhs, fpath rhs)
	{
		lhs.compress();rhs.compress();

		if(lhs.relative() || lhs.relative()) return fpath();

		if(lhs.root() !=  rhs.root()) return fpath();

		fpath::const_iterator iter1 = lhs.begin(),iter2 = rhs.begin(),end1 = lhs.end(),end2 = rhs.end();

		for(;iter1 != end1 && iter2 != end2; ++ iter1,++ iter2) if(*iter1 != *iter2) break;

		size_t counter = std::distance(iter1,end1);

		fpath result;

		if(counter > 0)
		{
			result.root((".."));

			-- counter;

			for(size_t i = 0 ; i < counter ; ++ i) result / ("..");
		}
		else
		{
			result.root(("."));
		}


		return result / fpath(iter2,end2);
	}
}}
