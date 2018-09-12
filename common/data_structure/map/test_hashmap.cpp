#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <sstream>
#include "stringmap.h"

using namespace std;

namespace common {
namespace map {

template <class KeyType, class ValueType>
class HashMap {

public:
	HashMap();

	~HashMap() = default;

	/// general function for getting Value from Key type
	ValueType get(const KeyType& key) const;

	/// general function for putting new pairs into map
	void put(const KeyType& key, const ValueType& value);

private:
	StringMap string_map_;

};

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap() :
	string_map_(StringMap())
{
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::get(const KeyType& key) const 
{
	string str = this->string_map_.get(to_string(key));
	istringstream stream(str);
	ValueType result;
	stream >> result;
	return result;
}



}
}

template<class T>
    T fromString(const std::string& s)
{
     std::istringstream stream (s);
     T t;
     stream >> t;
     return t;
}