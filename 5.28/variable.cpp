#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 5e18;

int main() {
	ll n; cin >> n;		
	auto f = [](ll a, ll b) {
		return (a*a*a + a*a*b + a*b*b + b*b*b);
	};	
	ll X = INF;
	ll j = 1000000;
	for(ll i = 0; i <= 1000000; i++) {
		while(f(i, j) >= n && j >= 0) {
			X = min(X, f(i, j));
			--j;
		}	
	}
	cout << X << endl;
}
