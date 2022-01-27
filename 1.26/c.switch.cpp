#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(m);
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		for(int j = 0; j < k; j++) {
			int x; cin >> x;
			a[i].push_back(x-1);
		}
	}
	vector<int> p(m);
	for(int i = 0; i < m; i++) cin >> p[i];
	int ans = 0;
	for(int bit = 0; bit < 1 << n; bit++) {
		bool ok = true;	
		for(int i = 0; i < m; i++) {
			int cnt = 0;
			for(auto j : a[i]) {
				if(bit & 1 << j) cnt++;
			}
			if(cnt % 2 != p[i]) ok = false;
		}
		if(ok) ans++;
	}
	cout << ans << endl;
}
