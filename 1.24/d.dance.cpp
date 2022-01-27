#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &a, vector<bool> s, int x, int n, int &ans) {
	int si = -1;
	int n2 = 2 * n;
	for(int i = 0; i < n2; i++) if(!s[i]) {
		si = i;
		break;
	}
	if(si == -1) {
		ans = max(ans, x);
		return;
	}
	s[si] = true;
	for(int i = 0; i < n2; i++) {
		if(!s[i]) {
			s[i] = true;
			dfs(a, s, x ^ a[si][i], n, ans);
			s[i] = false;
		}
	}
}

int main() {
	int n; cin >> n;
	int n2 = 2 * n;
	vector<vector<int>> a(n2, vector<int> (n2));
	for(int i = 0; i < n2; i++) {
		for(int j = i+1; j < n2; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	vector<bool> s(n2);	
	int ans = 0;
	dfs(a, s, 0, n, ans);
	cout << ans << endl;	
}
