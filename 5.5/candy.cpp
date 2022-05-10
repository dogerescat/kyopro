#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<ll> sum(n+1);	
	for(int i = 1; i <= n; i++) {
		sum[i] = (sum[i-1] + a[i-1]) % m;
	}
	map<int, int> mp;
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		ans += mp[sum[i]];	
		mp[sum[i]]++;
	}
	cout << ans << endl;
}
