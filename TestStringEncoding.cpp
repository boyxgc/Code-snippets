#include <iostream>
using namespace std;

#include "StringEncoding.h"


int main() {
	vector<string> v;
	v.push_back("");
	v.push_back(":\\:");
	v.push_back("hello\\");
	v.push_back(":world:");

	string str_enc = StringEncoding::encode(v);
	cout << str_enc << endl;

	vector<string> v_dec = StringEncoding::decode(str_enc);
	for(int i = 0; i < v_dec.size(); ++i) {
		cout << v_dec[i] << endl;
	}

	return 0;
}