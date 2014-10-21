#include <iostream>
using namespace std;

int divide(int A[], int low, int high) {
	int pivot = A[low];
	while(low < high) {
		while(low < high && A[high] > pivot) {
			high--;
		}
		if(low < high) {
			A[low] = A[high];
			low++;
		}
		while(low < high && A[low] <= pivot) {
			low++;
		}
		if(low < high) {
			A[high] = A[low];
			high--;
		}
	}
	A[low] = pivot;
	return low;
}

void quickSort(int A[], int low, int high) {
	if(low >= high) return;
	int mid = divide(A, low, high);
	quickSort(A, low, mid-1);
	quickSort(A, mid+1, high);
}


void quickSort(int A[], int size) {
	quickSort(A, 0, size-1);
}

int main() {

	int A[] = {4, 6, 10, 2, 1, 4, 2, 8};
	int n = sizeof(A)/sizeof(int);
	
	quickSort(A, n);

	for(int i = 0; i < n; ++i) {
		printf("%d ", A[i]);
	}
}