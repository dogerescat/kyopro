#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		int v = a[i] / x;
		int y = a[i] % x;
		if(v > k) {
			a[i] -= k * x;
			k = 0;
		} else {
			a[i] = y;
			k -= v;
		}
		if(k == 0) break;
	}
	sort(a.begin(), a.end(), greater<int>());
	ll ans = 0;
	for(int i : a) {
		if(k > 0) k--;	
		else ans += i;
	}
	cout << ans << endl;
}
