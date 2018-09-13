
#ifndef _STRINGMAP_H_
#define _STRINGMAP_H_

#include <iostream>
#include <string>

using namespace std;

namespace common {
namespace map {

class StringMap {

public:
	StringMap();

	~StringMap();

	/// make copying illegal
	StringMap(const StringMap& src) { }

	/// make assignment illegal
	StringMap& operator=(const StringMap& src) { return *this;}


	/// Funcion to get the value from the specific key
	string get(const string& key) const;

	/// Function to put the new pair into map
	/// if pair not exist, create a new cell
	/// if pair exist, update the value
	void put(const string& key, const string& value);

private:

	struct Cell {
		string key;
		string value;
		Cell* next;
	};

	static const int INITIAL_BUCKET_COUNT = 13;
	Cell** buckets_; // Pointer to pointer of cell
	int num_of_bucket_;

	/// private function
	Cell* findCell(const int& bucket, const string& key) const;

	
private:
	/// hash function definition
	static const int HASH_SEED = 5381;
	static const int HASH_MULTIPLIER = 33;
	static const int HASH_MASK = unsigned(-1) >> 1;

	int hashCode(const string& str) const;

};


} // namespace common
} // namespace map

#endif