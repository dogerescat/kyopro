#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());		
	priority_queue<ll> heap;
	heap.push(a[0]);
	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ll v = heap.top(); heap.pop();
		ans += v;
		heap.push(a[i]);
		heap.push(a[i]);
	}
	cout << ans << endl;
}
