
#define BOOST_TEST_MODULE queue_test
#include <boost/test/included/unit_test.hpp>
#include "queue.h"

using namespace std;
using namespace common;

Queue<int> buildOneTwoThree()
{
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	return queue;
}

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

BOOST_AUTO_TEST_CASE(test_size_queue)
{
	auto queue = buildOneTwoThree();
	BOOST_REQUIRE(queue.size() == 3);
}

BOOST_AUTO_TEST_CASE(test_empty_queue)
{
	auto queue = buildOneTwoThree();
	BOOST_REQUIRE(queue.isEmpty() == 0);
	queue = Queue<int>();
	BOOST_REQUIRE(queue.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(test_clear_queue)
{
	auto queue = buildOneTwoThree();
	BOOST_REQUIRE(queue.isEmpty() == 0);
	queue.clear();
	BOOST_REQUIRE(queue.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(test_dequeue_queue)
{
	auto queue = buildOneTwoThree();
	BOOST_REQUIRE(queue.dequeue() == 1);
	BOOST_REQUIRE(queue.size() == 2);
	BOOST_REQUIRE(queue.dequeue() == 2);
	BOOST_REQUIRE(queue.size() == 1);
	BOOST_REQUIRE(queue.dequeue() == 3);
	BOOST_REQUIRE(queue.size() == 0);
}

BOOST_AUTO_TEST_CASE(test_peek_queue)
{
	auto queue = buildOneTwoThree();
	BOOST_REQUIRE(queue.peek() == 1);
	BOOST_REQUIRE(queue.peek() == 1);
	BOOST_REQUIRE(queue.peek() == 1);
	BOOST_REQUIRE(queue.size() == 3);
}


BOOST_AUTO_TEST_SUITE_END()
