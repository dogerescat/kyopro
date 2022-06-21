#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> s(n+1);	
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i-1];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += (a[i-1] * i) - s[i];
	}
	cout << ans << endl;
}
