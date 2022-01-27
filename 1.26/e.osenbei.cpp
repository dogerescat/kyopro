#include <iostream>
#include <vector>
using namespace std;

int main() {
	int r, c; cin >> r >> c;
	vector<vector<int>> a(r, vector<int> (c));
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> a[i][j];
	int ans = 0;
	for(int bit = 0; bit < 1 << r; bit++) {
		int total = 0;
		for(int i = 0; i < c; i++) {
			int cnt = 0;
			for(int j = 0; j < r; j++) {
				if(bit & 1 << j) {
					if(!a[j][i]) cnt++;
				} else {
					if(a[j][i]) cnt++;
				}
			}
			total += max(cnt, r - cnt);
		}
		ans = max(ans, total);
	}
	cout << ans << endl;
}
