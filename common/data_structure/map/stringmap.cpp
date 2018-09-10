#include "stringmap.h"

using namespace std;

namespace common {
namespace map {

StringMap::StringMap() {

	num_of_bucket_ = INITIAL_BUCKET_COUNT;
	buckets_ = new Cell*[num_of_bucket_];

	for (int i=0;i<num_of_bucket_;i++) {
		buckets_[i] = NULL;
	}
}

StringMap::~StringMap() {
	for (int i=0;i<num_of_bucket_;i++) {
		Cell* cp = buckets_[i];
		while (cp != NULL) {
			Cell* oldCell = cp;
			cp = cp->next;
			delete oldCell;
		}
	}
}

string StringMap::get(const string& key) const {
	int bucket = hashCode(key) % num_of_bucket_;
	Cell* cp = this->findCell(bucket, key);
	return (cp != NULL) ? cp->value : "";
}

void StringMap::put(const string& key, const string& value) {
	int bucket = hashCode(key) % num_of_bucket_;
	Cell* cp = this->findCell(bucket, key);
	if (cp == NULL) {
		cp = new Cell;
		cp->key = key;
		cp->value = value;
		cp->next = this->buckets_[bucket];
		this->buckets_[bucket] = cp;
	} else {
		cp->value = value;
	}
}

StringMap::Cell* StringMap::findCell(const int& bucket, const string& key) const {
	Cell* head = this->buckets_[bucket];
	while (head != NULL && head->key != key) {
		head = head->next;
	}
	return head;
}

int StringMap::hashCode(const string& str) const {
	unsigned hash = HASH_SEED;
	int n = str.length();
	for (int i=0;i<n;i++) {
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return int(hash & HASH_MASK);
}

} // namespace common
} // namespace map