#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	queue<int> que;
	vector<queue<int>> M(m);
	vector<vector<int>> a(n);
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		for(int j = 0; j < k; j++) {
			int x; cin >> x;
			M[i].push(x-1);
		} 
		a[M[i].front()].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		if(a[i].size() == 2) que.push(i);
	}
	while(!que.empty()) {
		int c = que.front(); que.pop();
		for(int v : a[c]) {
			M[v].pop();
			if(!M[v].empty()) {
				a[M[v].front()].push_back(v);
				if(a[M[v].front()].size() == 2) {
					que.push(M[v].front());
				}
			}
		}
	}
	for(int i = 0; i < m; i++) {
		if(!M[i].empty()) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
