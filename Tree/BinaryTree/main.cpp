#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Node node1(1);
    Node node2(2);
    Node node3(3, &node1, &node2);
    Node node4(4, &node3, nullptr);
    Node node5(5);
    Node node6(6, &node5, nullptr);
    Node node7(7);
    Node node8(8, &node7, &node6);
    Node root(9, &node4, &node8);

    BinaryTree binary_tree(&root);

    cout << "====中序遍历====" << endl;
    binary_tree.inOrder();
    cout << endl;

    cout << "====前序遍历====" << endl;
    binary_tree.prevOrder();
    cout << endl;

    cout << "====后序遍历====" << endl;
    binary_tree.postOrder();
    cout << endl;

    cout << "====层序遍历(BFS)====" << endl;
    binary_tree.LevelOrder();
    cout << endl;

    return 0;
}
