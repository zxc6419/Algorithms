#pragma once

struct Node
{
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {};
};

class LinkList
{
public:

    static constexpr size_t npos = -1;

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

    int& operator[](size_t pos);
    void reverse();
    void sort();

private:
    Node head_;
};