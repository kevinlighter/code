#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

namespace common {
namespace map {

template <class KeyType, class ValueType>
class HashMap {

public:
	HashMap();

	~HashMap();

	/// copy constructor 
	HashMap(const HashMap<KeyType, ValueType>& hash_map);

	/// assignment operator
	HashMap<KeyType, ValueType>& operator=(const HashMap<KeyType, ValueType>& src);

	/// general function for getting Value from Key type
	ValueType get(const KeyType& key) const;

	/// general function for putting new pairs into map
	void put(const KeyType& key, const ValueType& value);

	/// size of the map
	int size() const;

	/// show the map empty or not
	bool isEmpty() const;

	/// show if the map contains a specific key
	bool containsKey(const KeyType& key) const;

	/// remove one key value pair from the map
	void remove(const KeyType& key);

	/// reset the map
	void clear();

	/// print out function
	ostream& operator<<(ostream& s, const HashMap<KeyType, ValueType>& hash_map);

	/// help function for to_string function
	static string to_string(const int& val);

	static string to_string(const double& val);

	static string to_string(const string& val);

private:
	
	struct Cell {
		KeyType key;
		ValueType value;
		Cell* next;
	};

	static const int INITIAL_BUCKET_COUNT = 13;

	/// instance variable
	int size_{0};

	Cell** buckets_; // Pointer to pointer of cell
	int num_of_bucket_;

	/// private function
	Cell* findCell(const int& bucket, const KeyType& key) const;

	/// deep copy function
	void deepCopy(const HashMap<KeyType, ValueType> src);


private:
	/// hash function definition
	static const int HASH_SEED = 5381;
	static const int HASH_MULTIPLIER = 33;
	static const int HASH_MASK = unsigned(-1) >> 1;


	int hashCode(const string& str) const;


};

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap()
{

	num_of_bucket_ = INITIAL_BUCKET_COUNT;
	buckets_ = new Cell*[num_of_bucket_];

	for (int i=0;i<num_of_bucket_;i++) {
		buckets_[i] = NULL;
	}
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap(const HashMap<KeyType, ValueType>& src)
{
	this->deepCopy(src);
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap()
{
	this->clear();
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::clear()
{
	for (int i=0;i<num_of_bucket_;i++) {
		Cell* cp = buckets_[i];
		while (cp != NULL) {
			Cell* oldCell = cp;
			cp = cp->next;
			delete oldCell;
		}
	}
	this->size_ = 0;
	this->num_of_bucket_ = 0;
}

template <typename KeyType, typename ValueType>
int HashMap<KeyType, ValueType>::size() const {
	return this->size_;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::isEmpty() const {
	return this->size_ == 0;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::containsKey(const KeyType& key) const
{
	string str = to_string(key);
	int bucket = hashCode(str) % num_of_bucket_;
	Cell* cp = this->findCell(bucket, key);
	return cp == NULL ? 0 : 1;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::remove(const KeyType& key)
{
	string str = to_string(key);
	int bucket = hashCode(str) % num_of_bucket_;
	Cell* head = this->buckets_[bucket];
	if (head == NULL)
		return;
	if (head->key == key) { 
		// if the head is the cell we find, point to the second cell
		// and delete the first one
		Cell* oldCell = head;
		head = head->next;
		this->buckets_[bucket] = head;
		delete oldCell;
		this->size_ --;
		return;
	}
	while (head->next != NULL) {
		// if the head is not the cell we find, first make sure the next cell not null, 
		if (head->next->key == key) {
			Cell* oldCell = head->next;
			head->next = head->next->next;
			delete oldCell;
			this->size_ --;
			return;
		} else {
			head = head->next;
		}
	}
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::get(const KeyType& key) const 
{
	string str = to_string(key);
	int bucket = hashCode(str) % num_of_bucket_;
	Cell* cp = this->findCell(bucket, key);
	return (cp != NULL) ? cp->value : "";
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::put(const KeyType& key, const ValueType& value)
{
	string str = to_string(key);
	int bucket = hashCode(str) % num_of_bucket_;
	Cell* cp = this->findCell(bucket, key);
	if (cp == NULL) {
		cp = new Cell;
		cp->key = key;
		cp->value = value;
		cp->next = this->buckets_[bucket];
		this->buckets_[bucket] = cp;
		/// increment by one of the size
		this->size_ ++;
	} else {
		cp->value = value;
	}
}

template <typename KeyType, typename ValueType>
typename HashMap<KeyType, ValueType>::Cell* HashMap<KeyType, ValueType>::findCell(const int& bucket, const KeyType& key) const {
	Cell* head = this->buckets_[bucket];
	while (head != NULL && head->key != key) {
		head = head->next;
	}
	return head;
}

template <typename KeyType, typename ValueType>
int HashMap<KeyType, ValueType>::hashCode(const string& str) const {
	unsigned hash = this->HASH_SEED;
	int n = str.length();
	for (int i=0;i<n;i++) {
		hash = this->HASH_MULTIPLIER * hash + str[i];
	}
	return int(hash & this->HASH_MASK);
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::deepCopy(const HashMap<KeyType, ValueType> src)
{
	this->num_of_bucket_ = src.num_of_bucket_;
	this->buckets_ = new Cell*[this->num_of_bucket_];
	this->size_ = src.size_;
	for (int i=0;i<this->num_of_bucket_;i++) {
		Cell* cp = src.buckets_[i];
		Cell* head = this->buckets_[i];
		while(cp != NULL) {
			head->key = cp->key;
			head->value = cp->value;
			cp = cp->next;
			head->next = cp;
			head = head->next;
		}
	}
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>& HashMap<KeyType, ValueType>::operator=(const HashMap<KeyType, ValueType>& src)
{
	if (this != &src) {
		this->clear();
		this->deepCopy(src);
	}
	return *this;
}

string to_string(string str) {
	return str;
}

string to_string(int val) {
	return std::to_string(val);
}

template <typename KeyType, typename ValueType>
string HashMap<KeyType, ValueType>::to_string(const int& val) {
	return std::to_string(val);
}

template <typename KeyType, typename ValueType>
string HashMap<KeyType, ValueType>::to_string(const double& val) {
	return std::to_string(val);
}

template <typename KeyType, typename ValueType>
string HashMap<KeyType, ValueType>::to_string(const string& val) {
	return val;
}

template <typename KeyType, typename ValueType>
ostream& operator<<(ostream& s, const HashMap<KeyType, ValueType>& hash_map)
{
	for (int i=0;i<hash_map.INITIAL_BUCKET_COUNT;i++) {
		Cell* head = hash_map.buckets_[i];
		if (head != NULL) {
			s << head->key << "(" << head->value << ")" << "  ->  ";
			head = head->next;
		} else {
			s << "NULL" << std::endl;
		}
	}
	return s;
}

} // namespace map
} // namespace common

#endif