#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, a, b; cin >> n >> a >> b;
	vector<ll> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];
	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ll y = x[i] - x[i-1];
		if(y * a > b) ans += b;
		else ans += y * a;
	}
	cout << ans << endl;
}
