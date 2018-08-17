all : test_binary_tree test_tree_to_list

test_binary_tree : binary_tree.h binary_tree.cpp test_binary_tree.cpp ../../../visualize/print.h ../../../visualize/print.cpp
	g++ -std=c++17 ../../../visualize/print.cpp binary_tree.cpp test_binary_tree.cpp -o $@

test_tree_to_list : binary_tree.h binary_tree.cpp tree_to_list.h tree_to_list.cpp test_tree_to_list.cpp ../../../visualize/print.h ../../../visualize/print.cpp
	g++ -std=c++17 ../../../visualize/print.cpp binary_tree.cpp tree_to_list.cpp test_tree_to_list.cpp -o $@