#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> l(m), r(m);
	for(int i = 0; i < m; i++) cin >> l[i] >> r[i];
	vector<vector<int>> sum(n+1, vector<int> (n+1));
	for(int i = 0; i < m; i++) sum[l[i]][r[i]]++;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		sum[i][j] += sum[i-1][j];
		sum[i][j] += sum[i][j-1];
		sum[i][j] -= sum[i-1][j-1];
	}
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		int ans = sum[r][r] - sum[r][l-1] - sum[l-1][r] + sum[l-1][l-1];
		cout << ans << endl;
	}
}
