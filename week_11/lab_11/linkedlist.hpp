#pragma once

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <exception>
struct Node
{
public:
    int value{};  // stores the data
    Node *next{}; // pointer to the next node
};

class LinkedList
{
private:
    Node *head{}; // first node (nullptr if empty)
    int n{};      // number of elements
    void clear(); // helper to clear all nodes

public:
    LinkedList();        // default constructor to initialize value to zero
    LinkedList(int dat); // constructor to add a Node with value, dat, to the list
    ~LinkedList();       // destructor
    bool empty();
    int size();
    void push_front(int v);   // insert at the front
    bool pop_front(int &out); // remove from the front
    void print();             // print contents

    void push_back(int);
    bool del(int val);
    Node &at(size_t index);
};

#endif // LINKEDLIST_HPP
