#include <iostream>
using namespace std;
using ll = long long;
ll f(ll a, ll b) {
	return (a*a*a+a*b*b+a*a*b+b*b*b); 
}
int main() {
	ll n; cin >> n;
	ll ans = 1001001001001001001;
	ll j = 1000000;
	for(ll i = 0; i <= 1000000; i++) {
		while(f(i, j) >= n && j >= 0) {
			ans = min(ans, f(i, j));
			--j;
		}
	}
	cout << ans << endl;
}
