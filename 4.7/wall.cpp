#include <iostream>
#include <vector>
using namespace std;
template<class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}

int main() {
	int h, w; cin >> h >> w;
	vector<vector<int>> dp(10, vector<int> (10));
	for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> dp[i][j];
	for(int k = 0; k < 10; k++) {
		for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) {
			if(i == j) continue;
			chmin(dp[i][j], dp[i][k] + dp[k][j]);
		}
	}
	vector<vector<int>> a(h, vector<int> (w));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
	int ans = 0;
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
		if(a[i][j] == -1) continue;
		ans += dp[a[i][j]][1];
	}
	cout << ans << endl;
}
