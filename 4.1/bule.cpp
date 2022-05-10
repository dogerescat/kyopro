#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll C[4010][4010];
void init() {
	C[0][0] = 1;
	for(int i = 0; i < 4000; i++) {
		for(int j = 0; j <= i; j++) {
			C[i+1][j] = (C[i+1][j] + C[i][j]) % MOD;
			C[i+1][j+1] = (C[i+1][j+1] + C[i][j]) % MOD;
		}
	}
}
int main() {
	int n, k; cin >> n >> k;
	init();	
	for(int i = 1; i <= k; i++) {
		ll ans = 0;
		ll red = C[n-k+1][i];	
		ll blue = C[k-1][i-1];
		ans = (ans + red * blue % MOD) % MOD;
		cout << ans << endl;
	}
}
