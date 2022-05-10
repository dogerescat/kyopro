#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h, vector<char> (w));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
	vector<vector<int>> dp(h+1, vector<int> (w+1));
	auto f = [&](int i, int j) {
		if(a[i][j] == '+') return 1;	
		else return -1;
	};
	for(int i = h-1; i >= 0; i--) for(int j = w-1; j >= 0; j--) {
		if((i+j) % 2 == 0) {
			int now = -INF;
			if(i < h-1) now = max(now, dp[i+1][j] + f(i+1, j));	
			if(j < w-1) now = max(now, dp[i][j+1] + f(i, j+1));
			if(now != -INF) dp[i][j] = now;
		} else {
			int now = INF;
			if(i < h-1) now = min(now, dp[i+1][j] - f(i+1, j));
			if(j < w-1) now = min(now, dp[i][j+1] - f(i, j+1));
			if(now != INF) dp[i][j] = now;
		}
	}
	if(dp[0][0] == 0) cout << "Draw" << endl;
	else if(dp[0][0] > 0) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
}
