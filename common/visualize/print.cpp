#include "print.h"

using namespace std;



ostream& operator<<(ostream& s, vector<int> vec)
{
	for (auto it = vec.begin(); it != vec.end(); it++) {
		s << " " << *it;
	}
	return s;
}