#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<bool> eratos() {
	vector<bool> res(1000001, true);
	res[0] = res[1] = false;
	for(int i = 2; i < 1000001; i++) {
		int j = 2;
		while(i * j < 1000001) {
			res[i * j] = false;
			j++;
		}
	}
	return res;
}
int main() {
	ll n; cin >> n;
	vector<bool> res = eratos();
	vector<ll> prime;	
	for(int i = 0; i < 1000001; i++) if(res[i]) prime.push_back(i);
	int m = prime.size();
	ll ans = 0;
	for(ll i = 0; i < m; i++) {
		ll left = i, right = m;
		while(right - left > 1) {
			ll mid = (left + right) / 2;	
			ll q = prime[mid] * prime[mid] * prime[mid];
			if(n/prime[i] >= q) left = mid;
			else right = mid;
		}
		ans += left - i;
	}
	cout << ans << endl;
}
