#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<vector<bool>> dp(n, vector<bool> (2));
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	dp[0][0] = dp[0][1] = true;
	for(int i = 1; i < n; i++) {
		if(dp[i-1][0]) {
			if(abs(a[i-1] - a[i]) <= k) dp[i][0] = true;	
			if(abs(a[i-1] - b[i]) <= k) dp[i][1] = true;
		} 
		if(dp[i-1][1]) {
			if(abs(b[i-1] - a[i]) <= k) dp[i][0] = true;
			if(abs(b[i-1] - b[i]) <= k) dp[i][1] = true;
		}
	}
	if(dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
