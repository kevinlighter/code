#include "kdtree.h"

using namespace common::tree::KDTree;

void testConstructor()
{
	KDTreeT<int>(5) kd1;
	KDTreeT<std::string>(10) kd2;
}

int main() {
	testConstructor();
}