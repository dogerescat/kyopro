#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
	string s; cin >> s;	
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		ll t, k; cin >> t >> k;
		k--;
		ll si = 0;
		if(t <= 60) {
			ll b = 1LL << t;
			si = k / b;
			k %= b;
		}
		ll r = __builtin_popcountll(k);
		ll l = t - r;
		ll x = l + r * 2 + (s[si] - 'A');
		char ans = 'A' + (x % 3);
		cout << ans << endl;
	}
}
