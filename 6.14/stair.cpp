#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;	
	while(n % 2 == 0) n /= 2;
	ll ans = 0;
	for(ll i = 1; i * i <= n; i++) {
		if(n % i) continue;
		ans += 2;
		if(i * i == n) ans--;
	}
	cout << ans * 2 << endl;
}
