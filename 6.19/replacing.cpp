#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	map<ll, ll> m;
	ll total = 0;	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];	
		m[a[i]]++;
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		ll b, c; cin >> b >> c;
		total -= b * m[b];
		total += c * m[b];
		m[c] += m[b];
		m.erase(b);
		cout << total << endl;
	}	
}
