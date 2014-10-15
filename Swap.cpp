#include <iostream>
using namespace std;

template<typename T> 
void myswap(T &a, T &b) {
	void *tmp = malloc(sizeof(T));
	memcpy(tmp, &a, sizeof(T));
	memcpy(&a, &b, sizeof(T));
	memcpy(&b, tmp, sizeof(T));
}

struct Node {
	int x;
	Node(int val){
	 x = val;
	}
	Node() {}
};

int main() {
	Node na(1);

	Node nb(3);

	cout << na.x << " " << nb.x << endl;

	myswap<Node>(na, nb);

	cout << na.x << " " << nb.x << endl;
}