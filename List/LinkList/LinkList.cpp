#include "LinkList.h"

#include <stdexcept>
#include <iostream>

using namespace std;

Node::Node(int data, Node *next)
        : data(data),
          next(next) {}

LinkList::LinkList()
        : head_(Node(-1)) {}

LinkList::~LinkList() {
    clear();
}

void LinkList::push_back(int data) {
    auto p = &head_;
    while (p->next) p = p->next;

    auto newNode = new Node(data);
    p->next = newNode;
}

void LinkList::push_front(int data) {
    auto newNode = new Node(data, head_.next);

    head_.next = newNode;
}

void LinkList::insert(int data, size_t pos) {
    auto p = &head_;
    size_t i = 0;
    while (p->next && i++ != pos)
        p = p->next;

    auto newNode = new Node(data, p->next);
    p->next = newNode;
}

int LinkList::pop_back() {
    if (empty()) throw runtime_error("LinkList is empty.");

    auto p = head_.next;
    auto prev = &head_;
    while (p->next) prev = p, p = p->next;

    int ret = p->data;
    prev->next = nullptr;

    delete p;

    return ret;
}

int LinkList::pop_front() {
    if (empty()) throw runtime_error("LinkList is empty.");

    auto p = head_.next;
    head_.next = p->next;

    int ret = p->data;
    delete p;

    return ret;
}

void LinkList::remove(int data) {
    auto p = &head_;

    while (p->next) {
        auto temp = p->next;
        if (temp->data == data) {
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}

void LinkList::remove_at(size_t pos) {
    auto p = &head_;
    size_t i = 0;
    while (p->next) {
        auto temp = p->next;
        if (i++ == pos) {
            p->next = temp->next;
            delete temp;
            break;
        }

        p = p->next;
    }
}

void LinkList::clear() {
    while (head_.next) {
        auto p = head_.next;
        head_.next = p->next;
        delete p;
    }
}

size_t LinkList::find(int data) {
    auto p = &head_;
    size_t i = 0;
    while (p->next) {
        auto temp = p->next;
        if (temp->data == data)
            return i;

        ++i, p = p->next;
    }

    return npos;
}

size_t LinkList::length() const {
    auto p = &head_;
    size_t i = 0;
    while (p->next)
        ++i, p = p->next;

    return i;
}

bool LinkList::empty() const {
    return head_.next == nullptr;
}

int &LinkList::operator[](size_t pos) {
    auto p = head_.next;
    size_t i = 0;
    while (p) {
        if (i++ == pos) break;
        p = p->next;
    }

    if (!p) throw out_of_range("Position is out of range.");

    return p->data;
}

void LinkList::reverse() {
    auto p = head_.next;
    if (!p) return;

    while (p->next) {
        auto temp = p->next;
        p->next = temp->next;
        temp->next = head_.next;
        head_.next = temp;
    }
}

std::ostream &operator<<(std::ostream &os, const LinkList &list) {
    os << "[";

    auto p = list.head_.next;
    while (p) {
        os << p->data
           << (p->next ? ", " : "");

        p = p->next;
    }

    os << "]";

    return os;
}
