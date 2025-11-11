#include "linkedlist.hpp"
#include <exception>

// Default constructor empty
LinkedList::LinkedList() : head(nullptr), n(0) {}

LinkedList::LinkedList(int dat)
{
    this->push_front(dat);
}

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

void LinkedList::push_back(int value)
{
    Node *nodePointer{head};
    // find position of last node
    while (nodePointer != nullptr)
    {
        if (nodePointer->next == nullptr)
        {
            break;
        }
        nodePointer = nodePointer->next;
    }

    // add location of new node to last nodes "next" value

    Node *newNode{new Node{value}};

    nodePointer->next = newNode;
    nodePointer = nodePointer->next;
}

bool LinkedList::del(int val)
{
    bool error{false};
    // Check if first node has value or is empty
    Node *nodePointer{head};
    Node *prevNode{};
    if (head != nullptr && nodePointer->value == val)
    {
        head = nodePointer->next;
        delete nodePointer;
    }
    else
    {

        error = true;
    }

    // While the node is valid, see if the value held is equal to the value given
    // If equal, delete the node. If not, move on to next node
    while (nodePointer != nullptr)
    {
        if (nodePointer->value == val)
        {
            Node *nextNode = nodePointer->next;
            delete nodePointer;
            nodePointer = prevNode;
            nodePointer->next = nextNode;
            return 1;
        }
        if (nodePointer->next == nullptr)
        {
            return 0;
        }
        prevNode = nodePointer;
        nodePointer = nodePointer->next;
    }
    if (error)
    {
        throw std::invalid_argument("cannot delete from empty list");
    }
    return 0;
}

Node &LinkedList::at(size_t index)
{
    Node *nodePointer{head};
    size_t count = 0;

    // While the next node is valid, return the address if its position matches the sent position
    // else, move on to next node
    while (nodePointer != nullptr)
    {
        if (count == index)
        {
            return *nodePointer;
        }
        if (nodePointer->next == nullptr)
        {
            break;
        }
        nodePointer = nodePointer->next;
        count++;
    }
    throw std::invalid_argument("not valid pos");
}