#include <iostream>
#include <vector>
#include <string>
using namespace std;
template<class T> void chmax(T &a, T b) {
	if(a < b) a = b;
}

int main() {
	string s, t; cin >> s >> t;
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i-1] == t[j-1]) {
				chmax(dp[i][j], dp[i-1][j-1] + 1);
			}		
			chmax(dp[i][j], dp[i-1][j]);
			chmax(dp[i][j], dp[i][j-1]);
		}
	}
	string ans;
	while(n && m) {
		if(dp[n][m] == dp[n-1][m]) {
			--n;	
		} else if(dp[n][m] == dp[n][m-1]) {
			--m;
		} else {
			--n; --m;
			ans.push_back(s[n]);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
