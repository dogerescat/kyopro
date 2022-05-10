#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> w(n), v(n), x(m);
	for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
	for(int i = 0; i < m; i++) cin >> x[i];	
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		--l, --r;
		vector<int> as;
		for(int j = 0; j < m; j++) {
			if(j < l || r < j) as.push_back(x[j]);
		}
		sort(as.begin(), as.end());
		vector<bool> used(n);	
		int ans = 0;
		for(auto a : as) {
			P best(-1, -1);
			for(int j = 0; j < n; j++) {
				if(used[j]) continue;
				if(w[j] > a) continue;
				best = max(best, P(v[j], j));	
			}
			int index = best.second;
			if(index == -1) continue;
			used[index] = true;
			ans += v[index];
		}
		cout << ans << endl;
	}
}
