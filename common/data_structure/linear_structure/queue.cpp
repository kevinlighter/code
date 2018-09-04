#include "queue.h"

using namespace std;

namespace common {

template <typename Scalar>
Queue<Scalar>::Queue() {
	capacity_ = INITIAL_CAPACITY;
	array_ = new Scalar[capacity_];
	head_ = tail_ = 0;
}

template <typename Scalar>
Queue<Scalar>::~Queue() {
	delete[] array_;
	capacity_ = 0;
	head_ = tail_ = 0;
}

template <typename Scalar>
int Queue<Scalar>::size() const {
	return (tail_ + capacity_ - head_) % capacity_;
}

template <typename Scalar>
bool Queue<Scalar>::isEmpty() const {
	return head_ == tail_;
}

template <typename Scalar>
void Queue<Scalar>::clear() {
	head_ = tail_ = 0;
}

template <typename Scalar>
void Queue<Scalar>::enqueue(const Scalar& val) {
	if (this->size() >= capacity_-1)
		this->expandCapacity();
	array_[tail_] = val;
	tail_ = (tail_+1) % capacity_;
}

template <typename Scalar>
Scalar Queue<Scalar>::dequeue() {
	assert(this->size()>0 && "queue dequeue error: empty queue!");
	Scalar result = array_[head_];
	head_ = (head_+1) % capacity_;
	return result;
}

template <typename Scalar>
Scalar Queue<Scalar>::peek() const {
	assert(this->size()>0 && "stack pop error: empty stack!");
	return array_[head_];
}

template <typename Scalar>
Queue<Scalar>::Queue(const Queue<Scalar>& src) {
	deepCopy(src);
}

template <typename Scalar>
void Queue<Scalar>::deepCopy(const Queue<Scalar>& src) {
	int size = src.size();
	this->capacity_ = size + INITIAL_CAPACITY;
	this->array_ = new Scalar[this->capacity_];
	for (int i=0;i<size;i++) {
		this->array_[i] = src.array_[(src.head_ + i) % src.capacity_];
	}
	this->head_ = 0;
	this->tail_ = size;
}

template <typename Scalar>
void Queue<Scalar>::expandCapacity() {
	int size = this->size();
	Scalar* oldArray = this->array_;
	array_ = new Scalar[2*this->capacity_];
	for (int i=0;i<size;i++) {
		array_[i] = oldArray[(this->head_ + i) % this->capacity_];
	}
	this->capacity_ *= 2;
	this->head_ = 0;
	this->tail_ = size;
	delete[] oldArray;
}

template <typename Scalar>
Queue<Scalar>& Queue<Scalar>::operator=(const Queue<Scalar>& src) {
	if (this != &src) {
		delete[] this->array_;
		this->deepCopy(src);
	}
	return *this;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
template class Queue<string>;

}

