#include <iostream>
#include <vector>
using namespace std;

int main() {
	int D, N; cin >> D >> N;
	vector<int> T(D);
	for(int i = 0; i < D; i++) cin >> T[i];
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	for(int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];
	vector<vector<int>> dp(D+1, vector<int> (N+1, -1));
	for(int i = 0; i < N; i++) {
		if(A[i] <= T[0] && T[0] <= B[i]) dp[1][i+1] = 0; 
	}
	for(int i = 1; i < D; i++) for(int j = 0; j < N; j++) {
		if(A[j] > T[i] || T[i] > B[j]) continue;		
		for(int k = 0; k < N; k++) {
			if(dp[i][k+1] != -1) {
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][k+1] + abs(C[j] - C[k]));
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = max(ans, dp[D][i]);
	}
	cout << ans << endl;
}
