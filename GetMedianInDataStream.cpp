#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct mycomp {
	bool reverse;
	mycomp(const bool & _reverse = false) {
		reverse = _reverse;
	}

	bool operator () (const int &a, const int & b) {
		if(reverse) {
			return a > b;
		} else {
			return a < b;
		}
	}
};

typedef priority_queue<int, vector<int>, mycomp> pq;

pq r_min_pq(mycomp(true));
pq l_max_pq;

void feedData(const int &num) {
	if(r_min_pq.empty()) { // put in right queue first
		r_min_pq.push(num);
	} else if (l_max_pq.empty()) {
		int r = r_min_pq.top();
		if(num > r) {
			r_min_pq.pop();
			r_min_pq.push(num);
			l_max_pq.push(r);
		} else {
			l_max_pq.push(num);
		}
	} else {
		int l = l_max_pq.top();
		int r = r_min_pq.top();

		if(num < l) {
			if(l_max_pq.size() > r_min_pq.size()) {
				r_min_pq.push(l_max_pq.top());
				l_max_pq.pop();
			} 
			l_max_pq.push(num);	
		} else if (num < r) {
			if(l_max_pq.size() > r_min_pq.size()) {
				r_min_pq.push(num);
			} else {
				l_max_pq.push(num);
			}
		} else {
			if(r_min_pq.size() > l_max_pq.size()) {
				l_max_pq.push(r_min_pq.top());
				r_min_pq.pop();
			}
			r_min_pq.push(num);
		}
	}
}

double getMedian() {
	if(l_max_pq.size() < r_min_pq.size()) {
		return r_min_pq.top();
	} else if(r_min_pq.size() > l_max_pq.size()) {
		return l_max_pq.top();
	} else {
		if(l_max_pq.size() == 0) return 0;
		return (l_max_pq.top() + r_min_pq.top())/2.0;
	}
}
