#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n+1);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<int> ());	
	ll c = 1;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll r = a[i], l = a[i+1]+1;
		if(k >= (r-l+1)*c) {
			ans += (r-l+1) * (r + l) / 2 * c;	
			k -= c * (r - l + 1);
		} else {
			ll x = k / c, y = k % c;
			ans += x * (2 * r - (x - 1)) / 2 * c;
			ans += y * (r - x);
			break;
		}
		c++;
	}
	cout << ans << endl;
}
