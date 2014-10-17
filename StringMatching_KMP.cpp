/*
Implmentation of KMP algorithm

@see http://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm
*/

#include <string>
#include <vector>
using namespace std;

int kmpSearch(string &, string &);
void kmpFillTable(string &, vector<int> &);

/**
 * @brief [perform kmp search using fault table]
 * @details [m (the beginning of the current match in S)
 * 			i (the position of the current character in W)
 * 			T (the fault table, computed elsewhere)]
 * 
 * @param W [the word sought]
 * @param S [text to be searched in]
 * 
 * @return [the start index at S at which W is found]
 */
 int kmpSearch(string &S, string &W) {
 	int i = 0;
 	int m = 0;
 	vector<int> T(W.size(), 0);
 	kmpFillTable(W, T);

 	while(m+i < S.size()) {
 		if(W[i] == S[m+i] ) {
 			i++;
 			if(i == W.size()) {
 				return m;
 			}
 		} else {
 			if(T[i] > 0) {
 				m = m + i - T[i];
 				i = T[i];
 			} else {
 				i = 0;
 				m++;
 			}
 		}
 	}

 	return -1;
 }

/**
 * @brief [fill the fault table for the pattern word]
 * @details [pos (the current position we are computing in T)
 * 			 cnd (the zero-based index of in W of the next 
 * 			 character of the current candidate string)]
 * 
 * @param W [pattern word]
 * @param r [fault table to be filled]
 */
 void kmpFillTable(string &W, vector<int> &T) {
 	if(T.size() < 1) return;
 	T[0] = 0;
 	if(T.size() < 2) return;
 	T[1] = 0;
 	if(T.size() < 3) return;
 	int pos = 2;
 	int cnd = 0;

 	while(pos < T.size()) {
 		if(W[pos-1] == W[cnd]) {
			//++cnd; T[pos] = cnd; pos++;
 			T[pos++] = ++cnd;
 		} else if(cnd > 0) {
 			cnd = T[cnd];
		} else {// cnd == 0
			T[pos++] = 0;
		}
	}
}

int main(void) {

	string S = "ABABDABACDABABCABABCD";
	string W = "ABABCABAB";

	printf("%d\n", kmpSearch(S, W));
	return 0;
}
