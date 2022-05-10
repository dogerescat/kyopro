#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;

int main() {
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	vector<int> dp(n, INF);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i + j < n) {
				dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
			}	
		}
	}
	cout << dp[n-1] << endl;
}
