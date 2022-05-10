#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; ll k; cin >> n >> k;	
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int bit = 0;
	ll K = k;
	while(K) {
		K >>= 1;
		bit++;
	}
	vector<ll> keta(41);
	for(int i = 0; i < n; i++) {
		ll x = a[i];	
		int j = 0;
		while(x) {
			if(x & 1) keta[j]++;
			x >>= 1;
			j++;
		}
	}
	vector<int> b;
	for(int i = 0; i < bit; i++) {
		if(keta[i] < n - keta[i]) b.push_back(1);	
		else b.push_back(0);
	}	
	int m = b.size();
	ll y = 0;
	vector<int> c;
	for(int i = m-1; i >= 0; i--) {
		if(b[i]) {
			if(y + (1LL << i) <= k) {
				c.push_back(i);
				y += (1LL << i);
			} 
		}
	} 
	for(int i : c) keta[i] = n - keta[i];
	ll ans = 0;
	for(int i = 0; i <= 40; i++) ans += keta[i] * (1LL << i);	
	cout << ans << endl;
}
