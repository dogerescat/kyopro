#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;	
	vector<ll> d(n), c(n);
	for(int i = 0; i < n; i++) cin >> d[i] >> c[i];
	ll D = 0, S = 0;
	for(int i = 0; i < n; i++) {
		S += d[i] * c[i];	
		D += c[i];
	}
	cout << D-1 + (S-1) / 9 << endl;
}
