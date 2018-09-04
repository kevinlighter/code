
#define BOOST_TEST_MODULE queue_test
#include <boost/test/included/unit_test.hpp>
#include "queue.h"

using namespace std;
using namespace common;

BOOST_AUTO_TEST_SUITE(queue_test)

BOOST_AUTO_TEST_CASE(test_create_queue)
{
	Queue<int> queue1;
	Queue<int> queue2;
	queue1.enqueue(3);
	queue2 = queue1; // assignment operator
	BOOST_REQUIRE(queue2.size() == 1);
	BOOST_REQUIRE(queue2.dequeue() == 3);
	BOOST_REQUIRE(queue1.size() == 1);
	BOOST_REQUIRE(queue1.dequeue() == 3);

	queue1.enqueue(3);
	Queue<int> queue3(queue1);
	BOOST_REQUIRE(queue3.size() == 1);
	BOOST_REQUIRE(queue3.dequeue() == 3);
}



BOOST_AUTO_TEST_SUITE_END()
