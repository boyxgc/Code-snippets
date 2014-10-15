#include <iostream>
#include <cmath>
using namespace std;

int count1sInPosition(int N, int pos) {
	int powOf10 = pow(10, pos);
	int nextPowOf10 = powOf10*10;

	int right = N % powOf10;
	int roundDown = N - N % nextPowOf10;
	int roundUp = roundDown + nextPowOf10;

	int digit = (N % nextPowOf10)/powOf10;

	if(digit < 1) {
		return roundDown/10;
	} else if (digit == 1) {
		return roundDown/10 + 1 + right;
	} else {
		return roundUp/10;
	}
}

int count1s(int N) {
	int tmp = N;
	int i = 0;
	int count = 0;
	while(tmp){
		count += count1sInPosition(N, i);
		tmp /= 10;
		i++;
	}
	return count;
}

int main() {

	cout << count1s(12) << endl;
}