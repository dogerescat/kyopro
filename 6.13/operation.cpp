#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> s(n+1);
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i-1];	
	for(int i = 0; i < q; i++) {
		ll x; cin >> x;
		ll index = lower_bound(a.begin(), a.end(), x) - a.begin();	
		ll ans = 0;
		if(index == n) {
			ans = abs(s[n] - x * n);	
			cout << ans << endl;
			continue;
		}
		ll left = abs(s[index] - x * index);
		index = upper_bound(a.begin(), a.end(), x) - a.begin();
		ll right = abs((s[n]-s[index]) - x * (n - index));
		ans = left + right;
		cout << ans << endl;
	}
}
