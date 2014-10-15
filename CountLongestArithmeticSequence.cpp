#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

int countLongestArithmeticSequence(vector<int> &nums) {
	// mapping from value difference to index pair
	unordered_map<int, vector<pair<int, int> > > diffMap;

	for(int i = 0; i < nums.size() - 1; ++i) {
		for(int j = i+1; j < nums.size(); ++j) {
			int diff = nums[i] - nums[j];
			diffMap[diff].push_back(make_pair(i, j));
		}
	}

	int longest = 0;

	unordered_map<int, vector<pair<int, int> > >::iterator it;
	for(it = diffMap.begin(); it != diffMap.end(); ++it) {
		vector<int> lens(nums.size(), 1); // init all the numbers in the pairs
                                          // doesn't matter also initlizing the nums that are not int the pair
		vector<pair<int, int> > pairs = it->second;

		for(int i = 0; i < pairs.size(); ++i) {
			lens[pairs[i].second] += lens[pairs[i].first];
			longest = max(longest, lens[pairs[i].second]);
		}		
	}

	return longest;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(5);
	v.push_back(9);
	v.push_back(7);

	cout << countLongestArithmeticSequence(v) << endl;
}