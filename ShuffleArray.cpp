#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void shuffle(int A[], int n) {

	srand(time(NULL));
	for(int i = n-1; i > 0; --i) {
		int j = rand()%(i+1);
		swap(A[i], A[j]);
	}
}

int main() {
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	shuffle(A, 10);
	for(int i = 0; i < 10; ++i) {
		printf("%d ", A[i]);
	}
}