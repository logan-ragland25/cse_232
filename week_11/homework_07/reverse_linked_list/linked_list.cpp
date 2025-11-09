#include "linked_list.hpp"

#include <iostream>

LinkedList::LinkedList() : head(nullptr), n(0) {}

void LinkedList::clear()
{
    while (head)
    {
        Node *temp{head};
        head = head->next;
        delete temp;
    }
    n = 0;
}

LinkedList::~LinkedList()
{
    clear();
}

bool LinkedList::empty() { return head == nullptr; }
int LinkedList::size() { return n; }

void LinkedList::push_front(int v)
{
    Node *newNode{new Node{v, head}};
    head = newNode;
    n++;
}

bool LinkedList::pop_front(int &out)
{
    if (empty())
        return false;
    Node *temp{head};
    out = temp->value;
    head = head->next;
    delete temp; // free memory
    n--;
    return true;
}

void LinkedList::print()
{
    Node *p{head};
    while (p != nullptr)
    {
        std::cout << p->value;
        if (p->next != nullptr)
            std::cout << " -> ";
        p = p->next;
    }
    std::cout << "\n";
}

void LinkedList::reverse() {
    Node *p{head};
    Node *lastLocation{};
    Node *nextLocation{};

    while (p != nullptr)
    {
        nextLocation = p->next;
        p->next = lastLocation;
        lastLocation = p;
        p = nextLocation;
    }
    head = lastLocation;
}