#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> &a, vector<vector<int>> &dp, int h, int w) {
	int res = 0;
	if(a[h+1][w] == '#' && a[h][w+1] == '#') return dp[h][w] = 1;;
	if(dp[h][w] != -1) return dp[h][w];
	if(a[h+1][w] == '.') res = max(res, dfs(a, dp, h+1, w)); 
	if(a[h][w+1] == '.') res = max(res, dfs(a, dp, h, w+1));	
	return dp[h][w] = res+1;
}
int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<vector<int>> dp(h+2, vector<int>(w+2, -1));	
	int ans = dfs(a, dp, 1, 1);
	cout << ans << endl;
}
