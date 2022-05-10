#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int n, m; cin >> n >> m;
	priority_queue<int, vector<int>> heap;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		heap.push(a);
	}
	for(int i = 0; i < m; i++) {
		int a = heap.top(); heap.pop();
		a /= 2;
		heap.push(a);
	}	
	ll ans = 0;	
	while(!heap.empty()) {
		ll v = heap.top(); heap.pop();
		ans += v;
	}
	cout << ans << endl;
}
