
#define BOOST_TEST_MODULE hashmap_test
#include <boost/test/included/unit_test.hpp>
#include "hashmap.h"

using namespace std;
using namespace common::map;

HashMap<int, int> create_hash_map_int_int() {
	HashMap<int, int> map;
	map.put(1, 100);
	map.put(2, 200);
	map.put(3, 300);
	return map;
}

HashMap<double, double> create_hash_map_double_double() {
	HashMap<double, double> map;
	map.put(1.1, 100.1);
	map.put(2.1, 200.1);
	map.put(3.1, 300.1);
	return map;
}

HashMap<string, int> create_hash_map_string_int() {
	HashMap<string, int> map;
	map.put("a", 100);
	map.put("b", 200);
	map.put("c", 300);
	return map;
}

HashMap<double, string> create_hash_map_double_string() {
	HashMap<double, string> map;
	map.put(1.1, "a");
	map.put(2.2, "b");
	map.put(3.3, "c");
	return map;
}

BOOST_AUTO_TEST_SUITE(hashmap_test)

BOOST_AUTO_TEST_CASE(test_hash_map_constructor)
{
	HashMap<int, int> map1;
	HashMap<double, double> map2;
	HashMap<string, int> map3;
	HashMap<double, string> map4;
}

BOOST_AUTO_TEST_CASE(test_hash_map_templates)
{
	BOOST_CHECK_NO_THROW(create_hash_map_int_int());
	BOOST_CHECK_NO_THROW(create_hash_map_double_double());
	BOOST_CHECK_NO_THROW(create_hash_map_string_int());
	BOOST_CHECK_NO_THROW(create_hash_map_double_string());
}

BOOST_AUTO_TEST_CASE(test_hash_map_size)
{
	auto a = create_hash_map_int_int();
	BOOST_REQUIRE(a.size() == 3);

	auto b = create_hash_map_double_double();
	BOOST_REQUIRE(b.size() == 3);

	auto c = create_hash_map_string_int();
	BOOST_REQUIRE(c.size() == 3);

	auto d = create_hash_map_double_string();
	BOOST_REQUIRE(d.size() == 3);
}

BOOST_AUTO_TEST_CASE(test_hash_map_empty)
{
	HashMap<int, int> map1;
	BOOST_REQUIRE(map1.isEmpty() == 1);
	map1.put(1,2);
	BOOST_REQUIRE(map1.isEmpty() == 0);
}

BOOST_AUTO_TEST_CASE(test_hash_map_contain_key)
{
	HashMap<double, double> map = create_hash_map_double_double();
	BOOST_REQUIRE(map.containsKey(1.1) == 1);
	BOOST_REQUIRE(map.containsKey(1.2) == 0);
}

BOOST_AUTO_TEST_CASE(test_hash_map_remove)
{
	HashMap<double, double> map = create_hash_map_double_double();
	BOOST_REQUIRE(map.containsKey(1.1) == 1);
	BOOST_REQUIRE(map.size() == 3);
	map.remove(1.1);
	BOOST_REQUIRE(map.containsKey(1.1) == 0);
	BOOST_REQUIRE(map.size() == 2);
	map.remove(1.2);
	BOOST_REQUIRE(map.size() == 2);
}

BOOST_AUTO_TEST_CASE(test_hash_map_printout)
{
	HashMap<int, int> map;
	map.put(1, 100);
	map.put(2, 200);
	map.put(3, 300);

	map.put(400, 100);
	map.put(500, 200);
	map.put(600, 300);

	std::cout << map << std::endl;
}



// BOOST_AUTO_TEST_CASE(test_get_stringmap)
// {
// 	StringMap map = create_string_map();
// 	BOOST_REQUIRE(map.get("a") == "1");
// 	BOOST_REQUIRE(map.get("b") == "2");
// 	BOOST_REQUIRE(map.get("c") == "3");
// 	BOOST_REQUIRE(map.get("d") == "");
// }

BOOST_AUTO_TEST_SUITE_END()