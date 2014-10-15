#ifndef STRING_ENCODING_H
#define STRING_ENCODING_H

#include <vector>
#include <string>
using namespace std;

class StringEncoding {

public:
	static string encode(vector<string> &strs) {
		string enc_str;

		for(int i = 0; i < strs.size(); ++i) {
			enc_str += to_string(strs[i].size()) + ":" + strs[i];
		}

		return enc_str;
	}

	static vector<string> decode(string enc_str) {
		vector<string> res;
		while(enc_str.size() > 0) {
			int i = 0;
			while(enc_str[i] != ':') i++;
			string size_str = enc_str.substr(0, i+1);
			int size = atoi(size_str.c_str());
			string data_str = enc_str.substr(i+1, size);
			res.push_back(data_str);
			enc_str = enc_str.substr(i+1+size);
		}

		return res;
	}
};

#endif