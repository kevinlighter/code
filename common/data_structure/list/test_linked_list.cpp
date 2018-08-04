#include "linked_list.h"

using namespace std;
using namespace common::list;

int main() {

//LinkedList::BuildOneTwoThree();

/// Create a dummy head here
shared_ptr<NodeT<int>> head = std::make_shared<NodeT<int>>(NodeT<int>(3));
//head->next = nullptr;

int a = 5;
push_front<int>(a, &head);

push_back<int>(4, &head);

std::cout << head << std::endl;



std::cout << BuildOneTwoThree() << std::endl;

std::cout << length(BuildOneTwoThree()) << std::endl;

auto p = create_dummy<int>();

auto p1 = create_dummy<std::string>("a");

std::cout << p1 << std::endl;


}