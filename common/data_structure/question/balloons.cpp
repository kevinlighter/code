#include <map>
#include <iostream>

using namespace std;

int recursion(map<int,int> array, map<int,int>::iterator iter, int& sum) {
	if (array.size() == 1) {
		auto it = array.begin();
		std::cout << "return sum befroe: " << sum << std::endl;
		int val = sum + it->second;
		sum = 0;
		std::cout << "this path return sum: " << val << std::endl;
		return val;
	}
	
	for (auto it = array.begin();it != array.end();)
	{
		std::cout << it->first << " " << it->second << " " << sum;
		map<int,int>::iterator left = array.find(it->first - 1);
		map<int,int>::iterator right = array.find(it->first + 1);

		// if (left == array.end() && right == array.end()) {
		// 	sum += 0;
		// }

		if (left != array.end() && right != array.end()) {
			std::cout << " 1:";
			sum += left->second * it->second * right->second;
		}
		
		if (left == array.end()) {
			std::cout << " 2:";
			sum += it->second * right->second;
		} 

		if (right == array.end()) {
			std::cout << " 3:";
			sum += it->second * left->second;
		}

		std::cout << " " << sum << std::endl;

		it = array.erase(it);
		map<int, int> array01 = array;
		recursion(array01, sum);
	}
}


int main() {
	map<int,int> array;
	array.insert(pair<int,int>(0,3));
	array.insert(pair<int,int>(1,1));
	array.insert(pair<int,int>(2,5));
	array.insert(pair<int,int>(3,8));

	int sum = 0;
	recursion(array, sum);

	return 0;

}