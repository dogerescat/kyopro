#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
	vector<int> p(a), q(b), r(c);
	for(int i = 0; i < a; i++) cin >> p[i];
	for(int i = 0; i < b; i++) cin >> q[i];
	for(int i = 0; i < c; i++) cin >> r[i];
	sort(p.begin(), p.end(), greater<int> ());	
	sort(q.begin(), q.end(), greater<int> ());	
	sort(r.begin(), r.end(), greater<int> ());	
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < x; i++) heap.push(p[i]);
	for(int i = 0; i < y; i++) heap.push(q[i]);
	for(int i = 0; i < c; i++) {
		int v = heap.top();
		if(v < r[i]) {
			heap.pop();	
			heap.push(r[i]);
		} else break;
	}
	ll ans = 0;
	while(!heap.empty()) {
		ans += heap.top();
		heap.pop();
	}
	cout << ans << endl;
}
