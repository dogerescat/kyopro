#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, W; cin >> N >> W;
	vector<int> v(N);
	vector<int> w(N);
	for(int i = 0; i < N; i++) cin >> v[i] >> w[i];
	vector<vector<int>> dp(N+1, vector<int> (W+1));
	for(int i = 1; i <= N; i++) for(int j = 0; j <= W; j++) {
		if(w[i-1] <= j) {
			dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
		}
		dp[i][j] = max(dp[i][j], dp[i-1][j]);
	}
	cout << dp[N][W] << endl;
}
