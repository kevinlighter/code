
#define BOOST_TEST_MODULE stack_test
#include <boost/test/included/unit_test.hpp>
#include "stack.h"

using namespace std;
using namespace common;

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



BOOST_AUTO_TEST_SUITE_END()
