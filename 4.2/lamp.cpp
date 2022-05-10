#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h+2, vector<char> (w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<vector<int>> b(h+2, vector<int> (w+2));
	vector<vector<int>> c(h+2, vector<int> (w+2));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
		if(a[i][j] !=  '#') {
			b[i][j] += b[i][j-1] + 1;
			c[i][j] += c[i-1][j] + 1;
		}
	}
	for(int i = h; i >= 1; i--) for(int j = w; j >= 1; j--) {
		if(a[i][j] != '#') {
			b[i][j] = max(b[i][j], b[i][j+1]);
			c[i][j] = max(c[i][j], c[i+1][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
		ans = max(ans, b[i][j] + c[i][j] - 1);
	}
	cout << ans << endl;
}
