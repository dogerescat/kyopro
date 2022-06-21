#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll a, b, n; cin >> a >> b >> n;	
	ll x = min(b-1, n);
	ll ans = (a * x / b) - a * (x / b);
	cout << ans << endl;
}
