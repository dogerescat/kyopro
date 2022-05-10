#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> a(60), p(60);

ll f(ll n, ll x) {
	if(n == 0) {
		if(x <= 0) return 0;
		else return 1;
	}
	if(x == 1) return 0;
	else if(x <= a[n-1] + 1) return f(n-1, x-1);
	else if(x == a[n-1] + 2) return p[n-1] + 1;
	else if(x <= 2 * a[n-1] + 2) return p[n-1] + 1 + f(n-1, x - a[n-1] - 2);
	else return 2 * p[n-1] + 1;
}
int main() {
	ll n, x; cin >> n >> x;	
	a[0] = 1, p[0] = 1;
	for(int i = 1; i <= 55; i++) {
		a[i] = 2 * a[i-1] + 3;
		p[i] = 2 * p[i-1] + 1;
	}
	ll ans = f(n, x);
	cout << ans << endl;
}
