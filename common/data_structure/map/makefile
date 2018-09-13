all : test_map test_hashmap

test_map : stringmap.h stringmap.cpp test_map.cpp
	g++ -std=c++17 stringmap.cpp test_map.cpp -o $@

test_hashmap : hashmap.h test_hashmap.cpp
	g++ -std=c++17 test_hashmap.cpp -o $@