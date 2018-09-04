#include "stack.h"

using namespace std;

namespace common {

template <typename Scalar>
Stack<Scalar>::Stack() {
	capacity_ = INITIAL_CAPACITY;
	array_ = new Scalar[capacity_];
	count_ = 0;
}

template <typename Scalar>
Stack<Scalar>::~Stack() {
	delete[] array_;
	capacity_ = 0;
	count_ = 0;
}

template <typename Scalar>
int Stack<Scalar>::size() const {
	return count_;
}

template <typename Scalar>
bool Stack<Scalar>::isEmpty() const {
	return count_ == 0;
}

template <typename Scalar>
void Stack<Scalar>::clear() {
	count_ = 0;
}

template <typename Scalar>
void Stack<Scalar>::push(const Scalar& val) {
	if (count_ == capacity_)
		this->expandCapacity();
	array_[count_++] = val;
}

template <typename Scalar>
Scalar Stack<Scalar>::pop() {
	assert(count_ > 0 && "stack pop error: empty stack!");
	return array_[--count_];
}

template <typename Scalar>
Scalar Stack<Scalar>::peek() const {
	assert(count_ > 0 && "stack pop error: empty stack!");
	return array_[count_-1];
}

template <typename Scalar>
Stack<Scalar>::Stack(const Stack<Scalar>& src) {
	deepCopy(src);
}

template <typename Scalar>
void Stack<Scalar>::deepCopy(const Stack<Scalar>& src) {
	this->count_ = src.count_;
	this->capacity_ = src.count_ + INITIAL_CAPACITY;
	this->array_ = new Scalar[this->capacity_];
	for (int i=0;i<this->count_;i++) {
		this->array_[i] = src.array_[i];
	}
}

template <typename Scalar>
void Stack<Scalar>::expandCapacity() {
	Scalar* oldArray = this->array_;
	this->capacity_ *= 2;
	array_ = new Scalar[this->capacity_];
	for (int i=0;i<this->count_;i++) {
		array_[i] = oldArray[i];
	}
	delete[] oldArray;
}

template <typename Scalar>
Stack<Scalar>& Stack<Scalar>::operator=(const Stack<Scalar>& src) {
	if (this != &src) {
		delete[] this->array_;
		this->deepCopy(src);
	}
	return *this;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<string>;

}

