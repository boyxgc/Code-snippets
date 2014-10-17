/**
 * give 1 million 32-bit integers, count how many 1s in them
*/

#include <unordered_map>
using namespace std;

int count1s(int num, unordered_map<int, int> &cache) {
	if (num == 0) return 0;

	if(cache.find(num) != cache.end())
		return cache[num];

	int count = 1 + count1s(num & (num-1), cache);
	cache[num] = count;

	return count;
}

int main() {
	unordered_map<int, int> cache;

	printf("%d\n", count1s(5, cache));
}