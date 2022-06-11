#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int q; cin >> q;
	ll t = 0;
	priority_queue<ll, vector<ll>, greater<ll>> heap;
	for(int i = 0; i < q; i++) {
		int p; ll x; cin >> p;		
		if(p == 1) {
			cin >> x;
			heap.push(x-t);
		} else if(p == 2) {
			cin >> x;
			t += x;
		} else {
			ll ans = heap.top(); heap.pop();
			ans += t;
			cout << ans << endl;
		}
	}
}
