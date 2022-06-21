#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll x, y, a, b; cin >> x >> y >> a >> b;
	ll ans = 0;
	while(x < (x + b) / a) {
		if(x * a >= y) break;	
		x *= a;
		ans++;
	}
	ll diff = y - x - 1;	
	if(diff > 0) ans += diff / b;
	cout << ans << endl;
}
