#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<int>> c(10, vector<int> (10));
	for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> c[i][j];
	vector<vector<int>> a(h, vector<int> (w));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
	for(int k = 0; k < 10; k++) {
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(a[i][j] == -1) continue;
			ans += c[a[i][j]][1];
		}
	}
	cout << ans << endl;
}
