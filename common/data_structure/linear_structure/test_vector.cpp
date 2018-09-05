
#define BOOST_TEST_MODULE vector_test
#include <boost/test/included/unit_test.hpp>
#include "vector.h"

using namespace common;

BOOST_AUTO_TEST_SUITE(vector_test)

BOOST_AUTO_TEST_CASE(test_create_vector)
{
	Vector<int> vector1;
	Vector<int> vector2;
	vector1.add(3);
	vector2 = vector1; // assignment operator
	BOOST_REQUIRE(vector2.size() == 1);
	BOOST_REQUIRE(vector2.get(0) == 3);
	BOOST_REQUIRE(vector1.size() == 1);
	BOOST_REQUIRE(vector1.get(0) == 3);

	Vector<int> vector3(vector1); // copy constructor
	BOOST_REQUIRE(vector3.size() == 1);
	BOOST_REQUIRE(vector3.get(0) == 3);
}



BOOST_AUTO_TEST_SUITE_END()