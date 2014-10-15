#include <iostream>
#include <string>
using namespace std;

#include "SuffixTree.h"

int main(int argc, char** argv) {

	if(argc != 3) {
		fprintf(stderr, "usage -- ./test str substr\n");
		exit(-1);
	}

	string str1(argv[1]);
	SuffixTree tree(str1);
	string str2(argv[2]);
	std::vector<int> v = tree.search(str2);

	printf("search \"%s\" in \"%s\" :", argv[2], argv[1]);
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout <<  endl;
	cout << "suffix: " << (tree.isSuffix(str2) ? "true" : "false")  << endl;

	return 0;
}