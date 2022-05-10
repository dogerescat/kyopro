#include <iostream>
#include <vector>
using namespace std;
const int MOD = 100000;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(m);
	vector<int> s(n+1);
	for(int i = 2; i <= n; i++) cin >> s[i];
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) s[i] = (s[i] + s[i-1]) % MOD; 
	int x = 1;
	int ans = 0;
	for(int i = 0; i < m; i++) {
		int y = x + a[i];	
		if(x > y) ans = (ans + s[x] - s[y]) % MOD; 
		else ans = (ans + s[y] - s[x]) % MOD;
		x = y;
	}
	cout << ans << endl;
}
