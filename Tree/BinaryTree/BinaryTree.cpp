#include "BinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

void BinaryTree::inOrder(Node* node)
{
    auto cur = node;
    if (cur) {
        inOrder(cur->left);
        cout << cur->data << " ";
        inOrder(cur->right);
    }
}

void BinaryTree::prevOrder(Node* node)
{
    auto cur = node;
    if (cur) {
        cout << cur->data << " ";
        inOrder(cur->left);
        inOrder(cur->right);
    }
}

void BinaryTree::postOrder(Node* node)
{
    auto cur = node;
    if (cur) {
        inOrder(cur->left);
        inOrder(cur->right);
        cout << cur->data << " ";
    }
}

void BinaryTree::inOrder()
{
    inOrder(head_);
}

void BinaryTree::prevOrder()
{
    prevOrder(head_);
}

void BinaryTree::postOrder()
{
    postOrder(head_);
}

void BinaryTree::LevelOrder()
{
    queue<Node*> q;
    q.push(head_);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
