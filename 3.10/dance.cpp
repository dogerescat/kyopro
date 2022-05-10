#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi a;
int n, n2, ans;
void dfs(vi seen, int x) {
	int si = -1;	
	for(int i = 0; i < n2; i++) if(!seen[i]) {
		si = i;
		break;
	}
	if(si == -1) {
		ans = max(ans, x);
		return;
	}
	seen[si] = true;
	for(int i = 0; i < n2; i++) {
		if(!seen[i] && si != i) {
			seen[i] = true;	
			dfs(seen, x ^ a[si][i]);
			seen[i] = false;
		}
	}
	
}
int main() {
	cin >> n;
	n2 = 2*n;
	a = vvi(n2, vi(n2));
	for(int i = 0; i < 2*n-1; i++) {
		for(int j = i+1; j < 2*n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	vi seen(n2);	
	dfs(seen, 0);
	cout << ans << endl;
}
