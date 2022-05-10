#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	int n; cin >> n;
	vector<vector<char>> s(2, vector<char>(n));
	for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> s[i][j];
	ll ans = 0;
	int i = 0;
	int prev = 0;
	if(s[0][0] == s[1][0]) {
		ans = 3;
		i++;
	} else {
		ans = 6;
		i += 2;
		prev = 1;
	}
	while(i < n) {
		if(prev) {
			if(s[0][i] == s[1][i]) {
				ans = ans * 1 % MOD;
				i++;
				prev = 0;
			} else {
				ans = ans * 3 % MOD;
				i += 2;
			}
		} else {
			ans = ans * 2 % MOD;
			if(s[0][i] == s[1][i]) {
				i++;
			} else {
				prev = 1;
				i += 2;
			}
		}
	}
	cout << ans << endl;
}
