#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;

pair<int, int> intDivide(int dividend, int divisor) {
	if(dividend == 0) {
		return make_pair(0, 0); // quotient and remainder
	}
	pair<int, int> res = intDivide(dividend/2, divisor);
	int q = res.first * 2;
	int r = res.second * 2 + (dividend % 2);

	if(r >= divisor) {
		q++;
		r -= divisor;
	}
	return make_pair(q, r);
}

string divide(string dividend, string divisor) {
	if(divisor == "0") return "N/A";

	unordered_map<int, int> remaindersMap;
	pair<int, int> divRes = intDivide(atoi(dividend.c_str()), atoi(divisor.c_str()));
	
	string result;
	result += to_string(divRes.first) + ".";
	int r = divRes.second;
	
	while(r > 0) {
		if(remaindersMap.find(r) != remaindersMap.end()) {
			result.insert(remaindersMap[r], "(");
			result.push_back(')');
			break;
		} else {
			remaindersMap[r] = result.size();
		}

		divRes = intDivide(r*10, atoi(divisor.c_str()));
		result += to_string(divRes.first);

		r = divRes.second;
	}

	if(result.back() == '.') result.pop_back();
	return result;
}

int main() {
	cout << divide("100", "8") << endl;
}