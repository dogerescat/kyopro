#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<pair<int, int>, int> P;
const int INF = 1e9;
template<class T> void chmin(T &a, T b) {
	if(a > b) {
		a = b;
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(n, INF));
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	vector<P> e(m);	
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		e[i].first.first = a;
		e[i].first.second = b;
		e[i].second = c;
		dp[a][b] = c;
		dp[b][a] = c;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				chmin(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}		
	int ans = 0;
	for(int k = 0; k < m; k++) {
		bool ok = false;
		int a = e[k].first.first;
		int b = e[k].first.second;
		int c = e[k].second;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(dp[i][a] + c + dp[b][j] == dp[i][j]) ok = true;	
			}
		}	
		if(!ok) ans++;
	}	
	cout << ans << endl;
}
