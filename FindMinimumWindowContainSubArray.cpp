#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define BIG 999999
//Solution 1
void outputPath(vector<int> &S, vector<int> &Q, vector<vector<int> > & minSub, int i , int j, int level)  {
	if(level == 0) {
		return;
	}

	int a = minSub[i-1][j]+1;
	int b = minSub[i-1][j-1]+1 + BIG*(S[i-1] == Q[j-1] ? 0 : 1);
	if(minSub[i][j] == a) {
		outputPath(S, Q, minSub, i-1, j, level -1);
		cout << S[i-1] << " ";
	} else {
		outputPath(S, Q, minSub, i-1, j-1, level -1);
		cout << S[i-1] << " ";
	}
}

int FindMinWinofSubArray(vector<int> &S, vector<int> &Q) {
	vector<vector<int> > minSub(S.size()+1, vector<int>(Q.size()+1, 0));
	
	for(int i = 0; i <= S.size(); ++i) minSub[i][0] = 0;
	for(int j = 1; j <= Q.size(); ++j) minSub[0][j] = BIG;

	for(int j = 1; j <= Q.size(); ++j) {
		for(int i = 1; i <= S.size(); ++i) {
			minSub[i][j] = min(
				minSub[i-1][j]+1, /* 1*(j != Q.size()), numbers after the last one don't count into length*/
				minSub[i-1][j-1]+1 + BIG*(S[i-1] == Q[j-1] ? 0 : 1));
		}
	}

	int minVal = BIG;
	int minIdx = -1;
	// find the minimum that contains Q
	for(int i = 0; i <= S.size(); ++i) {
		if(minSub[i][Q.size()] < minVal) {
			minVal = minSub[i][Q.size()];
			minIdx = i;
		}
	}

	outputPath(S, Q, minSub, minIdx, Q.size(), minVal);
	cout << endl;

	return minVal;//minSub[S.size()][Q.size()];
}

//Solution 2
vector<int> FindMinWinofSubArray2(vector<int> &S, vector<int> &Q) {
	vector<int> minWin;
	vector<vector<int> >indexes(Q.size());

	// get indexes map of each number in S
	unordered_map<int, vector<int> > index_map;
	for(int i = 0; i < S.size(); ++i) {
		index_map[S[i]].push_back(i);
	}
	// assign each number of Q with its indexes in S
	for(int i = 0; i < Q.size(); ++i) {
		indexes[i] = index_map[Q[i]];
	}

	vector<int> ptrs(Q.size(), 0);
	vector<vector<int> > wins(indexes[0].size());
	// for each indexes find its next closest
	// use ptrs to keep track of position in each vector
	for(int i = 0; i < indexes[0].size(); ++i) {
		wins[i].push_back(indexes[0][i]);
		for(int j = 1; j < Q.size(); ++j) {
			int ptr = ptrs[j];
			while(indexes[j][ptr] <= wins[i][j-1]) ptr++;
			ptrs[j] = ptr;
			wins[i].push_back(indexes[j][ptr]);
		}
	}
	// find the window of min size
	int minindex = -1;
	for(int i = 0; i < wins.size(); ++i) {
		if(minindex < 0 || (wins[i].back() - wins[i][0]) < (wins[minindex].back() - wins[minindex][0])) {
			minindex = i;
		}
	}
	// output number in the min window
	if(minindex < 0) {
		return vector<int>();
	} else {
		int start = wins[minindex][0];
		int end = wins[minindex].back() + 1;
		return vector<int>(S.begin()+start, S.begin()+end);
	}
}


int main() {
	int S [] = {1, 43, 4, 23, 1, 4, 4, 3, 5, 9, 1, 12, 5, 4, 3, 4};
	int Q [] = {1, 4, 3};
	vector<int> Sv, Qv;
	Sv.assign(S, S+sizeof(S)/sizeof(int));
	Qv.assign(Q, Q+sizeof(Q)/sizeof(int));

	cout << FindMinWinofSubArray(Sv, Qv) << endl;

	vector<int> minWin = FindMinWinofSubArray2(Sv, Qv);
	for(int i = 0; i < minWin.size(); ++i) {
		cout << minWin[i] << " ";
	}
	cout << endl;
	return 0;
}