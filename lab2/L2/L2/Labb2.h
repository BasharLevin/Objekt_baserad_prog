/*
Kinan Haj Rashid
*/
#ifndef Labb2_h
#define Labb2_h
#include <iostream>
#include <string>
#include <cstddef>

class  linked_list {
public:
    linked_list();
    linked_list(const linked_list &src);

    ~linked_list();
    
    linked_list& operator=(const linked_list &rhs);

    //appends elements from rhs
    linked_list& operator+=(const linked_list &rhs);

    // inserting elements
    void insert(double value, size_t pos);
    void push_front(double value);
    void push_back(double value);
    
    // accessing elements
    double front() const;
    double back() const;
    double at(size_t pos) const;    

    // output
    void print_list();
    void print_reverse() const;

    // removing elements
    void remove(size_t pos);
    double pop_front();
    double pop_back();

    // status
    size_t size() const;
    bool is_empty() const;

    struct node
    {
        node(double value);
        double value;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;

};
#endif