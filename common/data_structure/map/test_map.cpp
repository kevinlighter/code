
#define BOOST_TEST_MODULE stringmap_test
#include <boost/test/included/unit_test.hpp>
#include "stringmap.h"

using namespace std;
using namespace common::map;

StringMap create_string_map() {
	StringMap map;
	map.put("a", "1");
	map.put("b", "2");
	map.put("c", "3");
	return map;
}

BOOST_AUTO_TEST_SUITE(string_map_test)

BOOST_AUTO_TEST_CASE(test_put_stringmap)
{
	BOOST_CHECK_NO_THROW(create_string_map());
}

BOOST_AUTO_TEST_CASE(test_get_stringmap)
{
	StringMap map = create_string_map();
	BOOST_REQUIRE(map.get("a") == "1");
	BOOST_REQUIRE(map.get("b") == "2");
	BOOST_REQUIRE(map.get("c") == "3");
	BOOST_REQUIRE(map.get("d") == "");
}

BOOST_AUTO_TEST_SUITE_END()