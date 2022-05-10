#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<ll, int> P;
ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}
vector<P> fac(ll n) {
	vector<P> res;
	for(ll i = 2; i * i <= n; i++) {
		if(n % i) continue;
		res.push_back(P(i, 0));
		while(n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if(n != 1) res.push_back(P(n, 1));
	return res;
}
int main() {
	ll a, b; cin >> a >> b;	
	ll n = gcd(a, b);
	auto f = fac(n);
	cout << f.size() + 1 << endl;
}
