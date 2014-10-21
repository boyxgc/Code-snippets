#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// DFS

int CountWaysOfFindingWords(string str, int pos, vector<vector<char> > &matrix, int i, int j, unordered_map<string, int> &cached) {
	if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return 0;
	if(str[pos] != matrix[i][j]) return 0;
	if(pos == str.size() - 1) return 1;

	string key = to_string(i) + "+" + to_string(j) + "+" + to_string(pos);
	if(cached.find(key) != cached.end()) return cached[key];
	int ways = 0;
	ways += CountWaysOfFindingWords(str, pos+1, matrix, i+1, j, cached);
	ways += CountWaysOfFindingWords(str, pos+1, matrix, i-1, j, cached);
	ways += CountWaysOfFindingWords(str, pos+1, matrix, i, j+1, cached);
	ways += CountWaysOfFindingWords(str, pos+1, matrix, i, j-1, cached);

	cached[key] = ways;
	return ways;
}

int CountWaysOfFindingWords_DFS(string str, vector<vector<char> > &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int res = 0;
	unordered_map<string, int> cache;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j) {
			if(matrix[i][j] == str[0]) {
				res += CountWaysOfFindingWords(str, 0, matrix, i, j, cache);
			}
		}
	}
	return res;
}

// BFS
struct Node {
	int i;
	int j;
	int pos;
	Node(int iv, int jv, int posv): i(iv), j(jv), pos(posv) {}
};

void addNode(string &str, int pos, vector<vector<char> > &matrix, int i, int j, queue<Node> &q) {
	if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return;
	if(pos >= str.size()) return;
	if(matrix[i][j] == str[pos]) {
		Node node(i, j, pos);
		q.push(node);
	}
}

int CountWaysOfFindingWords_BFS(string str, vector<vector<char> > &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	queue<Node> q;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j) {
			if(matrix[i][j] == str[0]) {
				Node node(i, j, 0);
				q.push(node);
			}
		}
	}

	int count = 0;
	while(!q.empty()) {
		Node n = q.front();
		q.pop();
		if(n.pos == str.size()-1) {
			count++;
		} else {
			addNode(str, n.pos+1, matrix, n.i+1, n.j, q);
			addNode(str, n.pos+1, matrix, n.i-1, n.j, q);
			addNode(str, n.pos+1, matrix, n.i, n.j+1, q);
			addNode(str, n.pos+1, matrix, n.i, n.j-1, q);
		}
	}
	return count;
}

int main() {
	return 0;
}