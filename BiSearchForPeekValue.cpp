#include <iostream>
using namespace std;

// you have a array that contains number firstly in a ascending order and then in a descending order
// find the peek value

int biSearch(int A[], int n) {
	int l = 0, h = n-1, m;

	while(l <= h) {
		m = l + (h-l)/2;
		
		if(m-1 < 0 || m+1 >= n) return -1;

		if(A[m] > A[m-1] && A[m] > A[m+1]) {
			return A[m];
		} else if(A[m] > A[m-1]) {
			l = m+1;
		} else {
			h = m-1;
		}
	}
	return -1;
}

int main() {

	int A[] = {1,9,8,7,6,5,4,2};
	printf("%d\n", biSearch(A, 8));
	return 0;
}