#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void f(vector<vector<ll>> &A, ll &n, ll v, ll total, ll x, ll &ans) {
	if(v == n) {
		if(total == x) ans++;
		return;
	}
	ll len = A[v].size();	
	for(int i = 0; i < len; i++) {
		if(total > x / A[v][i]) continue;	
		f(A, n, v+1, total * A[v][i], x, ans);
	}
}

int main() {
	ll n, x; cin >> n >> x;
	vector<vector<ll>> A(n);
	for(ll i = 0; i < n; i++) {
		ll l; cin >> l;
		for(ll j = 0; j < l; j++) {
			ll a; cin >> a;
			A[i].push_back(a);
		} 
	}
	ll ans = 0;
	f(A, n, 0, 1, x, ans);
	cout << ans << endl;
}
