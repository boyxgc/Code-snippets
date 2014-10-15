#include <iostream>
using namespace std;

int findSoleNumber(int A[], int n) {
	int ones = 0;
	int twos = 0;
	int threes = 0;

	for(int i = 0; i < n; ++i) {
		twos |= ones & A[i];
		ones ^= A[i];

		threes = ones & twos;
		twos &= ~threes;
		ones &= ~threes;
	}

	return ones;
}

int main() {

	int A[] = {2,1,4,5,1,4,2,2,4,1,5,5,6};
	cout << findSoleNumber(A, sizeof(A)/sizeof(int));
	return 0;
}