all : stack_test queue_test vector_test

stack_test : stack.h test_stack.cpp
	g++ -std=c++17 test_stack.cpp -o $@

queue_test : queue.h test_queue.cpp
	g++ -std=c++17 test_queue.cpp -o $@

vector_test : vector.h test_vector.cpp
	g++ -std=c++17 test_vector.cpp -o $@