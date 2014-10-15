#include <iostream>
using namespace std;

int reverseBits(unsigned int num) {
	int reverse = 0;
	while(num) {
		reverse = (reverse << 1) | (num & 1);
		num >>= 1;
	}
	return reverse;
}

int main() {
	cout << reverseBits(10);
}