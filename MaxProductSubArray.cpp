#include <iostream>
using namespace std;

int maxProduct(int A[], int n) {
    int New = A[0];
    int old = A[0];
    int Max = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] == 0)
            New = old = 0;
        else if ((A[i] < 0 && old > 0 && New > 0) || (A[i] < 0 && old < 0 && New < 0) || (A[i] > 0 && old < 0 && New < 0)) {
            New = A[i];
            old *= A[i];
        } else if (old == 0 && New == 0) {
            old = New = A[i];
        }
        else {
            old *= A[i];
            New *= A[i];
        }

        int current = max(New, old);
        if (current > Max)
            Max = current;
    }

    return Max;
}

int main() {

    int A[] = {4, 5, -3, -5, -6};

    cout << maxProduct(A, 5);
}