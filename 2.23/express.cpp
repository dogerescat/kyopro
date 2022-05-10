#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>> a(n+1, vector<int> (n+1));
	for(int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		a[l][r]++;
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		a[i][j] += a[i][j-1];
	}
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		int ans = 0;
		for(int j = l; j <= r; j++) ans += a[j][r];
		cout << ans << endl;
	}
}
