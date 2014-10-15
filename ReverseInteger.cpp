#include <iostream>
using namespace std;

int reverseInt(int a) {
	int rev_a = 0;
	int b = a < 0 ? -a : a;

	while(b) {
		rev_a = rev_a*10 + b%10;
		b /= 10;
	}

	return a < 0 ? -rev_a : rev_a;
}

int main() {

	cout << reverseInt(-980) << endl;
	return 0;
}