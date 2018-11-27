#include "LinkList.h"

int main(int argc, char* argv[])
{
    LinkList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.push_front(4);

    list.insert(999, 0);

    int value = list.pop_back();

    list.remove(999);

    list.remove_at(10);

    size_t i = list.find(2);

    size_t len = list.length();

    int val = -1;
    val = list[100];
    list[1] = 333;
    val = list[1];

    return 0;
}
