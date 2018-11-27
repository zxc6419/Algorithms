#pragma once

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d = -1) : data(d), left(nullptr), right(nullptr) {};
    Node(int d, Node* l, Node* r) : data(d), left(l), right(r) {};
};

class BinaryTree
{
public:
    BinaryTree(Node* head) : head_(head) {};
    void inOrder();
    void prevOrder();
    void postOrder();
    void LevelOrder();
private:
    Node* head_;

    void inOrder(Node* node);
    void prevOrder(Node* node);
    void postOrder(Node* node);
};