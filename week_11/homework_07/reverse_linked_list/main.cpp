#include "linked_list.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    LinkedList list{};
	list.push_front(10);
	list.push_front(5);
	list.push_front(25);
	list.push_front(20);
	list.push_front(100);
	list.reverse();
	list.print();

    return 1;
}