#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int q; cin >> q;
	for(int k = 0; k < q; k++) {
		string X, Y; cin >> X >> Y;	
		int n = X.size(), m = Y.size();
		vector<vector<int>> dp(n+1, vector<int> (m+1));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(X[i-1] == Y[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
		}	
		cout << dp[n][m] << endl;
	}
}
