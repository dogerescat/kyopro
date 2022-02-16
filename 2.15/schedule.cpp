#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MOD = 10007;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int f(vvi &dp, int &n, string &t, int v, int S) {
	if(v == 0) {
		if(S & 1 && S & (1 << (t[0]-'0'))) return 1;
		else return 0;
	}
	if(!(S & (1 << (t[v]-'0')))) return 0;	
	if(dp[v][S] != -1) return dp[v][S];	
	dp[v][S] = 0;
	for(int i = 0; i < 1 << 3; i++) {
		if(i & S) {
			dp[v][S] += f(dp, n, t, v-1, i);
			dp[v][S] %= MOD;
		}
	}
	return dp[v][S];
}
int main() {
	int n; string s;
	cin >> n >> s;
	string t;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'J') t.push_back('0');
		else if(s[i] == 'O') t.push_back('1');
		else t.push_back('2');
	}
	vvi dp(n+1, vi(1<<3, -1));
	int ans = 0;
	for(int i = 0; i < 1 << 3; i++) {
		ans += f(dp, n, t, n-1, i);
		ans %= MOD;
	}
	cout << ans << endl;
}
