#include <iostream>
#include <string>
#include <assert.h>

#ifndef _stack_h_
#define _stack_h_

using namespace std;

namespace common {

template <class Scalar>
class Stack {

public:
	Stack();
	~Stack();

	/// Copy constructor
	Stack(const Stack<Scalar>& src);

	/// assignment operator
	Stack<Scalar>& operator=(const Stack<Scalar>& src);

	/// Return the size of a stack
	int size() const;

	/// Return if the stack is empty
	bool isEmpty() const;

	/// Remove all element of a stack
	void clear();

	/// Add element into the stack
	void push(const Scalar& val);

	/// Remove the top element and return it
	/// If call of an empty stack, output an error
	Scalar pop();

	/// get the element of the stack from top 
	/// without removing it, output an error if empty
	Scalar peek() const;

	/// help function to show stack
	friend ostream& operator<<(ostream& s, Stack<Scalar> stack) {
		if (!stack.isEmpty()) {
			s << stack.pop() << " ";
			s << stack;
		} 

		return s;
	}

private:
	static const int INITIAL_CAPACITY = 10;
	/// use an array to store the stack

	/// Instance variables
	Scalar* array_;
	int capacity_;
	int count_;

	/// private method prototype
	void deepCopy(const Stack<Scalar>& src);
	void expandCapacity();
};

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

}




#endif