#include <iostream>
using namespace std;

void PrintNum(int n){
	cout << n << "\t";
}

void PrintLine(int n, int i){
    // Number of integers in current matrix
	int n2 = n*n;
    // Number of itegers in previous matrix of size n - 1
	int m2 = (n - 1)*(n - 1);

	if (n % 2 == 0){
		if (i == n - 1){
            // n is even and we are at the last row so just
            // print it
			for(int k = n2; k > n2 - n; k--){
				PrintNum(k);
			}
		} else {
            // Print row from previous matrix of size n - 1
            // first and then print value that belongs to current
            // matrix. Previous matrix is at the top left corner
            // so no need to adjust row index
			PrintLine(n - 1, i);
            // Skip all integers from previous matrix and upper
            // ones in this columnas integers must form clockwise
            // spiral
			PrintNum(m2 + 1 + i);
		}
	} else {
		if (i == 0) {
            // n is odd and we are at the first row so just
            // print it
			for(int k = m2 + n; k <= n2; k++) {
				PrintNum(k);
			}
		} else {
            // Print value that belongs to current matrix and
            // then print row from previous matrix of size n - 1
            // Skip all integers from previous matric and bottom
            // ones in this column as integers must form clockwise
            // spiral
			PrintNum(m2 + n - i);
            // Previous matrix is at the bottom right corner so
            // row index must be reduced by 1
			PrintLine(n - 1, i - 1);
		}
	}
}


void PrintSpiral(int n) {
	for(int i = 0; i < n; i++) {
		PrintLine(n, i);
		cout << endl;
	}
}

int main() {
	PrintSpiral(5);
	return 0;
}