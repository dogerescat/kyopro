#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using P = pair<int, int>;

int f(vector<vector<int>> &a, vector<P> &v, vector<bool> &used, int &n) {
	if(v.size() == n) {
		int res = 0;
		for(int i = 0; i < n; i++) res ^= a[v[i].first][v[i].second];
		return res;
	}	
	int left = 0;
	for(int i = 0; i < 2*n; i++) {
		if(!used[i]) {
			left = i;
			break;
		}
	}
	used[left] = true;
	int res = 0;
	for(int i = 0; i < 2*n; i++) {
		if(!used[i]) {
			v.push_back(P(left, i)); used[i] = true;	
			res = max(res, f(a, v, used, n));
			v.pop_back(); used[i] = false;

		}
	}
	used[left] = false;
	return res;
}
int main() {
	int n; cin >> n;
	vector<vector<int>> a(2*n, vector<int>(2*n));
	for(int i = 0; i < 2*n; i++) {
		for(int j = i+1; j < 2*n; j++) cin >> a[i][j];
	}
	vector<P> v;
	vector<bool> used(2*n);
	int ans = f(a, v, used, n);
	cout << ans << endl;
}
