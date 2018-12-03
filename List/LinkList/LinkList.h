#pragma once

#include <cstddef>
#include <iosfwd>

struct Node {
    int data;
    Node *next;

    explicit Node(int data, Node *next = nullptr);
};

class LinkList {
public:

    friend std::ostream &operator<<(std::ostream &os, const LinkList &list);

    static constexpr size_t npos = size_t(-1);

    LinkList();

    ~LinkList();


    void push_back(int data);

    void push_front(int data);

    void insert(int data, size_t pos);

    int pop_back();

    int pop_front();

    void remove(int data);

    void remove_at(size_t pos);

    void clear();

    size_t find(int data);

    size_t length() const;

    bool empty() const;

    int &operator[](size_t pos);

    void reverse();

private:
    Node head_;
};

std::ostream &operator<<(std::ostream &os, const LinkList &list);