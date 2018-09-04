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
}


#endif