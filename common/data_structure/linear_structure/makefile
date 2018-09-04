all : stack_test queue_test

stack_test : stack.h stack.cpp test_stack.cpp
	g++ -std=c++17 stack.cpp test_stack.cpp -o $@

queue_test : queue.h queue.cpp test_queue.cpp
	g++ -std=c++17 queue.cpp test_queue.cpp -o $@