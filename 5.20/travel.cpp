#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1001001001;
template <class T> void chmin(T &a, T b) {
	if(a > b) {
		a = b;
	}
}
int main() {
	int N, M, R; cin >> N >> M >> R;
	vector<int> r(R);
	for(int i = 0; i < R; i++) cin >> r[i];
	sort(r.begin(), r.end());
	vector<vector<int>> dp(N, vector<int>(N, INF));
	for(int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		dp[a][b] = c;
		dp[b][a] = c;
	}
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) { 
				chmin(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	int ans = INF;
	do {
		int tot = 0;	
		for(int i = 1; i < R; i++) tot += dp[r[i]-1][r[i-1]-1];
		chmin(ans, tot);
	} while(next_permutation(r.begin(), r.end()));
	cout << ans << endl;
}
