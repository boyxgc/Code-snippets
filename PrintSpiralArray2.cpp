#include <iostream>
using namespace std;

// print spiral
void printSpiral(int);
// print the ith line of sprial matrix of size n
void printLine(int, int);
// print a single number
void printNum(int);

void printSpiral(int n) {
	for(int i = 0; i < n; ++i) {
		printLine(n, i);
		cout << endl;
	}
}

void printLine(int n, int i) {
	int n2 = n*n;
	int m2 = (n-1)*(n-1);

	if(n%2) {
		if(i == 0) {
			for(int k = 0; k < n; ++k) {
				printNum(k+m2+n);
			}
		} else {
			printNum(m2+n-i);
			printLine(n-1, i-1);
		}
	} else {
		if(i == n-1) {
			for(int k = 0; k < n; ++k) {
				printNum(n2-k);
			}
		} else {
			printLine(n-1, i);
			printNum(m2+i+1);
		}
	}
}

void printNum(int num) {
	cout << num << "\t";
}

int main() {
	printSpiral(5);
	return 0;
}
