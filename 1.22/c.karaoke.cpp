#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i+1; j < m; j++) {
			ll total = 0;
			for(int k = 0; k < n; k++) {
				total += max(a[k][i], a[k][j]);
			}	
			ans = max(ans, total);	
		}
	}
	cout << ans << endl;
}
