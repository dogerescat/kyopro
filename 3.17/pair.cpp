#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	queue<int> que;
	vector<queue<int>> A(m);
	vector<vector<int>> memo(n);
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		for(int j = 0; j < k; j++) {
			int a; cin >> a; --a;
			A[i].push(a);
		}
		memo[A[i].front()].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		if(memo[i].size() == 2) {
			que.push(i);
		}
	}
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(auto i : memo[v]) {
			A[i].pop();
			if(!A[i].empty()) {
				memo[A[i].front()].push_back(i);
				if(memo[A[i].front()].size() == 2) {
					que.push(A[i].front());
				}
			}
		}
	}
	for(int i = 0; i < m; i++) {
		if(!A[i].empty()) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
