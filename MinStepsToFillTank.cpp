#include <iostream>
#include <vector>
using namespace std;

struct Path {
	int container;
	int prev;
	Path() {
		container = -1; 
		prev = -1;
	}
};
void fillTank(int N, vector<int> &containers) {
	vector<int> minSteps(N + 1, 0);
	vector<Path> paths(N+1, Path());

	for(int i = 1; i <= N; ++i) {
		int minSofar = INT_MAX;
		int containerSize = -1;
		for(int j = 0; j < containers.size() && containers[j] <= i; ++j) {
			int steps = minSteps[i-containers[j]];
			if(steps < minSofar) {
				minSofar = steps;
				containerSize = containers[j];
			}
		}
		minSteps[i] = minSofar + 1;
		paths[i].container = containerSize;
		paths[i].prev = i - containerSize;
	}

	cout << "min steps: " << minSteps[N] << endl;
	cout << "path: ";
	Path path = paths[N];
	while(path.prev >= 0) {
		cout << path.container << " ";
		path = paths[path.prev];
	}
}

int main() {
	int A[] = {1,3,5,6,25};
	vector<int> containers;
	containers.assign(A, A+sizeof(A)/sizeof(int));

	fillTank(71, containers);
}