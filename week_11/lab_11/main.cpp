#include "linkedlist.hpp"
#include <iostream>

int main()
{
    LinkedList list{5};
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.push_front(0);
    list.push_back(6);

    list.del(2);
    list.print();

    Node node = list.at(4);
    std::cout << node.value << "\n";

    return 0;
}