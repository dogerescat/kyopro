#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int n, a, b; cin >> n >> a >> b;
	vector<ll> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	priority_queue<ll> heap;
	for(int i = 0; i < n; i++) heap.push(h[i]);
	ll cnt = 0;
	ll curb = 0;
	while(!heap.empty()) {
		ll v = heap.top(); heap.pop();	

		if(v - curb <= 0) break;
		if(v - a + b > 0) heap.push(v - a + b);
		cnt++;
		curb += b;
	}
	cout << cnt << endl;
}
