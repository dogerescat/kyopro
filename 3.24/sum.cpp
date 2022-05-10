#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;	
	vector<ll> a(n+1);	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n / i; j++) {
			a[i * j]++;
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		ans += a[i] * i;
	}
	cout << ans << endl;
}
