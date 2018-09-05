#include <iostream>
#include <assert.h>

#ifndef _vector_h_
#define _vector_h_

using namespace std;

namespace common {

template <class Scalar>
class Vector {

public:
	Vector();

	/// This constructor specified the length of vector
	/// and can specified initial value for all the elements
	Vector(const int& n, const Scalar& val = Scalar());

	/// copy constructor
	Vector(const Vector<Scalar>& src);

	/// assignment operator
	Vector<Scalar> & operator=(const Vector<Scalar>& src);

	~Vector();

	/// return the size of a vector
	int size() const;

	/// return true if the vector is empty, false otherwise
	bool isEmpty() const;

	/// remove all elements from the vector
	void clear();

	/// get the element with the index, return error if not in range
	Scalar get(const int& index) const;

	/// replace the element the specified index in the vector, 
	/// the previous value is overwritten
	/// return an error if not in array range
	void set(const int& index, const Scalar& val);

	/// insert the element into the vector before the specified index
	/// all subsequent elements are shifted one position to the right
	/// return an error if the index is not in range
	/// if index == count, equal to push_back()
	void insert(const int& index, const Scalar& val);

	/// remove the element at the specified index from the vector
	/// all subsequent elements are shifted one position to the left
	/// return an error if the index is outside of the range
	void remove(const int& index);

	/// add a value to the end of the vector
	void add(const Scalar& val);

	/// operator: []
	/// overload [] to select elements from the vector
	/// return by reference to set value
	Scalar& operator[](const int& index);

	/// print out function
	friend ostream& operator<<(ostream& s, const Vector<Scalar>& vec) {
		for (int i=0;i<vec.size();i++) {
			s << vec[i] << " ";
		}
		s << std::endl;
		return s;
	}

private:

	static const int INITIAL_CAPACITY = 10;

	/// instance variables
	Scalar *array_;
	int capacity_;
	int count_;

	void deepCopy(const Vector<Scalar>& src);
	void expandCapacity();
};


template <typename Scalar>
Vector<Scalar>::Vector() {
	count_ = 0;
	capacity_ = INITIAL_CAPACITY;
	array_ = new Scalar[capacity_];
}

template <typename Scalar>
Vector<Scalar>::Vector(const int& n, const Scalar& val) {
	capacity_ = n>INITIAL_CAPACITY ? n : INITIAL_CAPACITY;
	array_ = new Scalar[capacity_];
	count_ = n;
	for (int i=0;i<n;i++) {
		array_[i] = val;
	}
}

template <typename Scalar>
Vector<Scalar>::Vector(const Vector<Scalar>& src) {
	this->deepCopy(src);
}

template <typename Scalar>
Vector<Scalar>::~Vector() {
	delete[] array_;
}

template <typename Scalar>
int Vector<Scalar>::size() const {
	return count_;
}

template <typename Scalar>
bool Vector<Scalar>::isEmpty() const {
	return count_ == 0;
}

template <typename Scalar>
void Vector<Scalar>::clear() {
	count_ = 0;
}

template <typename Scalar>
Scalar Vector<Scalar>::get(const int& index) const {
	assert(index >= 0 && "vector get error: index < 0");
	assert(index < count_ && "vector get error: get out of range vector index!");
	return array_[index];
}

template <typename Scalar>
void Vector<Scalar>::set(const int& index, const Scalar& val) {
	assert(index >= 0 && "vector set error: index < 0");
	assert(index < count_ && "vector set error: get out of range vector index!");
	array_[index] = val;
}

template <typename Scalar>
void Vector<Scalar>::insert(const int& index, const Scalar& val) {
	assert(index >= 0 && "vector insert error: index < 0");
	assert(index <= count_ && "vector insert error: get out of range vector index!");
	if (count_ >= capacity_)
		this->expandCapacity();
	for (int i=count_;i>index;i--) {
		array_[i] = array_[i-1];
	}
	array_[index] = val;
	count_ ++;
}

template <typename Scalar>
void Vector<Scalar>::remove(const int& index) {
	assert(index >= 0 && "vector remove error: index < 0");
	assert(index < count_ && "vector remove error: get out of range vector index!");
	count_ --;
	for (int i=index;i<count_;i++) {
		array_[i] = array_[i+1];
	}
}

template <typename Scalar>
void Vector<Scalar>::add(const Scalar& val) {
	this->insert(this->count_, val);
}

template <typename Scalar>
Scalar& Vector<Scalar>::operator[](const int& index) {
	assert(index >= 0 && "vector [] operator error: index < 0");
	assert(index < count_ && "vector [] operator error: out of range");
	return array_[index];
}

template <typename Scalar>
Vector<Scalar> & Vector<Scalar>::operator=(const Vector<Scalar>& src)
{
	if (this != &src) {
		delete [] array_;
		deepCopy(src);
	}
	return *this;
}

template <typename Scalar>
void Vector<Scalar>::deepCopy(const Vector<Scalar>& src) {
	this->capacity_ = src.capacity_ + INITIAL_CAPACITY;
	this->count_ = src.count_;
	this->array_ = new Scalar[this->capacity_];
	for (int i=0;i<src.count_;i++) {
		this->array_[i] = src.array_[i];
	}
}

template <typename Scalar>
void Vector<Scalar>::expandCapacity() {
	Scalar* oldArray = this->array_;
	this->capacity_ *= 2;
	this->array_ = new Scalar[this->capacity_];
	for (int i=0;i<this->count_;i++) {
		this->array_[i] = oldArray[i];
	}
	delete[] oldArray;
}

}

#endif