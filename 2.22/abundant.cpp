#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<ll> sum(n+1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i-1];
	for(int i = 1; i <= n; i++) {
		ll ans = 0;
		for(int j = 0; j + i <= n; j++) {
			ans = max(ans, sum[i+j] - sum[j]);	
		}
		cout << ans << endl;
	}
}
