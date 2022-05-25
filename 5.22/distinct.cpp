#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;	
	for(int i = 0; i < n; i++) {
		auto l = lower_bound(a.begin(), a.end(), a[i]);	
		auto r = upper_bound(a.begin(), a.end(), a[i]);
		if(l == a.end() || r == a.end()) continue;
		ans += (l - a.begin()) * (n - (r - a.begin()));
	}
	cout << ans << endl;
}
