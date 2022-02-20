#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll x; cin >> x;
	if(x < 0) {
		int a = x % 10;
		ll ans = x / 10;
		if(a) ans--;
		cout << ans << endl;
	} else {
		ll ans = x / 10;
		cout << ans << endl;
	}
}
