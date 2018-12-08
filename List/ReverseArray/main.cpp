#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int>& A) {
    const int n = A.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n-i-1];
        A[n-i-1] = temp;
    }
}

void reverse_array2(vector<int>& A) {
    int li = -1;
    int hi = A.size();

    while (++li < --hi) {
        int temp = A[li];
        A[li] = A[hi];
        A[hi] = temp;
    }
}

void print(const vector<int>& A) {
    for (auto it = A.begin(); it != A.end(); ++it)
        cout << *it
             << (next(it) != A.end() ? ", " : "\n");
}

int main() {
    vector<int> A {1,3,5,7,9,2,4,6,8,0};

    cout << "----Origin Array----" << endl;
    print(A);

    cout << "----Reversed1 Array----" << endl;
    reverse_array(A);
    print(A);

    cout << "----Reversed2 Array----" << endl;
    reverse_array2(A);
    print(A);

    return 0;
}