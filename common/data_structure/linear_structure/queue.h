#include <iostream>
#include <string>
#include <assert.h>

#ifndef _queue_h_
#define _queue_h_

using namespace std;

namespace common {

template <class Scalar>
class Queue {

public:
	Queue();
	~Queue();

	/// Copy constructor
	Queue(const Queue<Scalar>& src);

	/// assignment operator
	Queue<Scalar>& operator=(const Queue<Scalar>& src);

	/// Return the size of a Queue
	int size() const;

	/// Return if the stack is empty
	bool isEmpty() const;

	/// Remove all element of a Queue
	void clear();

	/// Add element into the stack
	void enqueue(const Scalar& val);

	/// Remove the top element and return it
	/// If call of an empty stack, output an error
	Scalar dequeue();

	/// get the element of the stack from top 
	/// without removing it, output an error if empty
	Scalar peek() const;

	/// help function to show stack
	friend ostream& operator<<(ostream& s, Queue<Scalar> queue) {
		if (!queue.isEmpty()) {
			s << queue.dequeue() << " ";
			s << queue;
		} 

		return s;
	}

private:
	static const int INITIAL_CAPACITY = 10;
	/// use an array to store the queue

	/// Instance variables
	Scalar* array_;
	int capacity_;
	int head_;
	int tail_;

	/// private method prototype
	void deepCopy(const Queue<Scalar>& src);
	void expandCapacity();
};
}


#endif