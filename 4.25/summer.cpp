#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int n, m; cin >> n >> m;
	const int M = 100005;
	vector<vector<int>> x(M);
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		--a;
		x[a].push_back(b);
	}
	priority_queue<int> heap;	
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j : x[i]) {
			heap.push(j);	
		}
		if(!heap.size()) continue;
		ll v = heap.top(); heap.pop();
		ans += v;
	}	
	cout << ans << endl;
}
