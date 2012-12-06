#include <lake/properties.hpp>

namespace lake{

	void properties::insert(const char * key, const char * val)
	{
		const_iterator iter = _container.upper_bound(key);

		if(iter != _container.end())
		{
			_container.insert(++ iter, std::make_pair(key,val));
		}
		else
		{
			_container.insert(std::make_pair(key,val));
		}
	}

	properties::range properties::search(const char * key)
	{
		return _container.equal_range(key);
	}

	properties::const_range properties::search(const char * key) const
	{
		return _container.equal_range(key);
	}

}