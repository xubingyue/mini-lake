#include <sstream>
#include <stdexcept>
#include <lake/mini-lake-pom.hpp>

namespace lake{namespace pom{

	property::property(const std::string & name, const std::string & val)
		:_name(name),_value(val)
	{

	}

	property::property(const std::string & pair)
	{
		std::string::size_type found = pair.find("=");

		if(found == pair.npos)
		{ 
			std::stringstream stream;

			stream << "invalid property value pair :" << pair;

			throw std::runtime_error(stream.str()); 
		}

		_name = pair.substr(0,found);

		_value = pair.substr(found + 1);
	}


	bool pom::set_property(const property & p)
	{
		return set_property(p.name(),p.value());
	}

	bool pom::set_property(const std::string & name, const std::string & val)
	{
		bool status = false;

		bool multi = false;

		for(size_t i = 0 ; i < sizeof(config::MultiValueProperties)/sizeof(const char*); i ++ )
		{
			if(name == config::MultiValueProperties[i])
			{
				multi = true; break;
			}
		}

		properties_type::const_iterator iter = _properties.find(name);

		if(_properties.end() != iter) status = true;

		if(status)
		{
			if(iter->second.value() == val) return false;

			if(multi)
			{
				_properties.insert(++ iter ,std::make_pair(name,property(name,val)));

				return false;
			}
			else
			{
				_properties.erase(name);
			}
		}
		
		_properties.insert(std::make_pair(name,property(name,val)));

		return status;
	}

	pom::property_values pom::get_property(const std::string & name) const
	{
		typedef std::pair <properties_type::const_iterator, properties_type::const_iterator> range_type;

		pom::property_values values;

		properties_type::const_iterator iter = _properties.find(name);

		range_type range = _properties.equal_range(name);

		//found nothing!!!!
		if(range.first == _properties.end() && range.second == _properties.end()) return values;
		
		while(range.first != range.second)
		{
			values.push_back(range.first->second.value().c_str());

			++ range.first;
		}

		return values;
	}

	//////////////////////////////////////////////////////////////////////////

	bool project::accept(visitor * v)
	{
		return v->visit(this);
	}
}}