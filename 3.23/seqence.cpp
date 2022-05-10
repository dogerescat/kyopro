#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, x, m; cin >> n >> x >> m;
	int len = 0;
	vector<int> id(m, -1);
	vector<ll> a;
	ll total = 0;
	while(id[x] == -1) {
		a.push_back(x);	
		id[x] = len;
		len++;
		total += x;
		x = (x * x) % m;
	}
	int c = len - id[x];
	ll s = 0;
	for(int i = id[x]; i < len; i++) s += a[i];
	ll ans = 0;
	if(len > n) {
		for(int i = 0; i < n; i++) ans += a[i];
	} else {
		ans += total;	
		n -= len;
		ans += s * (n / c);
		n %= c;
		for(int i = 0; i < n; i++) ans += a[id[x] + i];
	}
	cout << ans << endl;
}
