#include "queue.hpp"

Queue::Queue() : head(nullptr), tail(nullptr), n(0) {}

void Queue::clear()
{
    while (head)
    {
        Node *tmp{head};
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    n = 0;
}

Queue::~Queue()
{
    clear();
}

bool Queue::empty() { return head == nullptr; }
int Queue::size() { return n; }

void Queue::enqueue(int v)
{
    Node *newNode{new Node{v, nullptr}};
    if (empty())
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    n++;
}

bool Queue::dequeue(int &out)
{
    if (empty())
        return false;
    Node *temp{head};
    out = temp->value;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;
    delete temp;
    n--;
    return true;
}

void Queue::print()
{
    Node *p{head};
    while (p)
    {
        std::cout << p->value;
        if (p->next)
            std::cout << " -> ";
        p = p->next;
    }
    std::cout << '\n';
}

void Queue::pairedRoot(int input) {
    enqueue(input);
    while (input > 99) {
        int sum = 0;
        while (input > 9) {
            sum += input % 100;
            input /= 100;
        }
        sum += input;
        enqueue(sum);

        input = sum;
    }
}
