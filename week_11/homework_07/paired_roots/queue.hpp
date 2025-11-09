#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

struct Node
{
    int value{};
    Node *next{};
};

class Queue
{
private:
    Node *head{}; // front
    Node *tail{}; // back
    int n{};

    void clear();

public:
    Queue();
    ~Queue();
    bool empty();
    int size();
    void enqueue(int v);
    bool dequeue(int &out);
    void print();
    void pairedRoot (int input);
};

#endif // QUEUE_HPP