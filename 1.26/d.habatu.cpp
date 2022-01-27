#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (n));
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	int ans = 0;
	for(int bit = 0; bit < 1 << n; bit++) {
		vector<int> b;	
		for(int i = 0; i < n; i++) if(bit & 1 << i) b.push_back(i);
		bool ok = true;
		for(auto i : b) {
			for(auto j : b) {
				if(i == j) continue;
				if(!a[i][j]) ok = false; 		
			}
		}
		if(ok) ans = max(ans, (int)b.size());
	}
	cout << ans << endl;
}
