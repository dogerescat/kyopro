#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
template <class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}
int main() {
	int N, X, Y; cin >> N >> X >> Y;
	vector<int> a(N), b(N);	
	for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
	vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(X+1,vector<int>(Y+1, INF)));
	for(int i = 0; i <= N; i++) dp[i][0][0] = 0;
	for(int i = 0; i < N; i++) {
		for(int x = 0; x <= X; x++) {
			for(int y = 0; y <= Y; y++) {
				chmin(dp[i+1][x][y], dp[i][x][y]);
				chmin(dp[i+1][min(X, x+a[i])][min(Y, y+b[i])],dp[i][x][y]+1);
			}
		}
	}	
	if(dp[N][X][Y] == INF) cout << -1 << endl;
	else cout << dp[N][X][Y] << endl;
}
