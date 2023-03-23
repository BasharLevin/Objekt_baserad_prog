#ifndef lab2_h
#define lab2_h
#include <iostream>
#include <string>
#include <cstddef>

class Linked_list{

    public:
    Linked_list();
    Linked_list(const Linked_list &src);

    ~Linked_list();

    Linked_list& operator =(const Linked_list &rhs);

    Linked_list& operator += (const Linked_list &rhs);

    void insert(double value, size_t pos);
    void push_front(double value );
    void push_back(double value );

    double front() const;
    double back() const;
    double at(size_t pos) const;

    void remove(size_t pos);
    double pop_front();
    double pop_back();

    size_t size() const;
    bool is_empty() const;

    void print_lista() const;
    void print_reverse() const;

    private :
    struct node{
        node(double value);
        double value;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;
};
#endif
