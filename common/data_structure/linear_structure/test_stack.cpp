
#define BOOST_TEST_MODULE stack_test
#include <boost/test/included/unit_test.hpp>
#include "stack.h"

using namespace std;
using namespace common;

Stack<int> buildOneTwoThree()
{
	Stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	return stack1;
}

BOOST_AUTO_TEST_SUITE(stack_test)

BOOST_AUTO_TEST_CASE(test_create_stack)
{
	Stack<int> stack1;
	Stack<int> stack2;
	stack1.push(3);
	stack2 = stack1; // assignment operator
	BOOST_REQUIRE(stack2.size() == 1);
	BOOST_REQUIRE(stack2.pop() == 3);
	BOOST_REQUIRE(stack1.size() == 1);
	BOOST_REQUIRE(stack1.pop() == 3);

	stack1.push(3);
	Stack<int> stack3(stack1);
	BOOST_REQUIRE(stack3.size() == 1);
	BOOST_REQUIRE(stack3.pop() == 3);
}

BOOST_AUTO_TEST_CASE(test_size_stack)
{
	auto stack1 = buildOneTwoThree();
	BOOST_REQUIRE(stack1.size() == 3);
}

BOOST_AUTO_TEST_CASE(test_empty_stack)
{
	auto stack1 = buildOneTwoThree();
	BOOST_REQUIRE(stack1.isEmpty() == 0);
	stack1 = Stack<int>();
	BOOST_REQUIRE(stack1.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(test_clear_stack)
{
	auto stack1 = buildOneTwoThree();
	BOOST_REQUIRE(stack1.isEmpty() == 0);
	stack1.clear();
	BOOST_REQUIRE(stack1.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(test_pop_stack)
{
	auto stack1 = buildOneTwoThree();
	BOOST_REQUIRE(stack1.pop() == 3);
	BOOST_REQUIRE(stack1.pop() == 2);
	BOOST_REQUIRE(stack1.pop() == 1);
	BOOST_REQUIRE(stack1.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(test_peek_stack)
{
	auto stack1 = buildOneTwoThree();
	BOOST_REQUIRE(stack1.peek() == 3);
	BOOST_REQUIRE(stack1.peek() == 3);
	BOOST_REQUIRE(stack1.peek() == 3);
	BOOST_REQUIRE(stack1.isEmpty() == 0);
}



BOOST_AUTO_TEST_SUITE_END()
