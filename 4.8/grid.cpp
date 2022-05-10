#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w, n; cin >> h >> w >> n;
	vector<int> a(n);
	vector<vector<int>> ans(h, vector<int>(w));
	for(int i = 0; i < n; i++) cin >> a[i];
	bool iseven = true;
	int y = 0, x = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < a[i]; j++) {
			ans[y][x] = i+1;	
			if(iseven) x++;
			else x--;
			if(x == -1) {
				iseven = true;
				x = 0;
				y++;
			}
			if(x == w) {
				iseven = false;
				x = w - 1;
				y++;
			}
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}
