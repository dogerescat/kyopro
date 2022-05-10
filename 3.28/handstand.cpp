#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<vector<ll>> cnt(10, vector<ll> (10));
	for(int i = 1; i <= n; i++) {
		string s = to_string(i);	
		int m = s.size();
		cnt[s[0]-'0'][s[m-1]-'0']++;
	}
	ll ans = 0;
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			ans += cnt[i][j] * cnt[j][i];
		}
	}
	cout << ans << endl;
}
