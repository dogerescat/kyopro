#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
	ll n, h; cin >> n >> h;
	vector<ll> a(n), b(n);	
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	ll cnt = 0;
	for(int i = 0; i < n; i++) {
		if(h <= 0) break;
		if(b[i] <= a[0]) break;
		h -= b[i];
		cnt++;
	}
	if(h > 0) cnt += (h + a[0] - 1) / a[0];
	cout << cnt << endl;
}
