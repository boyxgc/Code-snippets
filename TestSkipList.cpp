#include <iostream>

#include "SkipList.h"

using namespace std;

int main() {
	SkipList list(4, 0.5);

	srand(time(NULL));
	list.insert(20);
	list.insert(1);
	list.insert(4);
	list.insert(5);
	list.insert(2);
	list.insert(11);
	list.insert(7);

	list.print();

	printf("Find 11: %d\n", list.find(11));
	printf("Find 111: %d\n", list.find(111));
	printf("Find 2: %d\n", list.find(2));

	printf("Remove 2: %d\n", list.remove(2));
	list.print();
	printf("Find 2: %d\n", list.find(2));

	return 0;
}