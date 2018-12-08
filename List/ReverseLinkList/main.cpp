#include <iostream>

struct Node {
    int data;
    Node *next;

    explicit Node(int data, Node *next = nullptr)
            : data(data), next(next) {}
};

Node* reverse_linklist(Node* head){
    Node* new_head = nullptr;
    while(head) {
        Node* next = head->next;
        head->next = new_head;

        new_head = head;
        head = next;
    }

    return new_head;
}

void print(Node* head) {
    if (head) {
        std::cout << head->data
                  << (head->next ? ", " : "\n");
        print(head->next);
    }
}

int main() {

    Node g(7);
    Node f(6, &g);
    Node e(5, &f);
    Node d(4, &e);
    Node c(3, &d);
    Node b(2, &c);
    Node a(1, &b);

    Node* head = &a;
    std::cout << "----Origin data----" << std::endl;

    print(head);

    auto new_head = reverse_linklist(head);

    std::cout << "----reversed data----" << std::endl;
    print(new_head);

    return 0;
}