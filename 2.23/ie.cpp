#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll H, W, K, V; cin >> H >> W >> K >> V;
	vector<vector<ll>> A(H+1, vector<ll> (W+1));
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) cin >> A[i][j];
	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			A[i][j] += A[i-1][j];	
			A[i][j] += A[i][j-1];
			A[i][j] -= A[i-1][j-1];
		}
	}
	ll ans = 0;
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) {
		for(int ii = i; ii <= H; ii++) for(int jj = j; jj <= W; jj++) {
			ll value = A[ii][jj] - A[i-1][jj] - A[ii][j-1] + A[i-1][j-1];
			ll cnt = (ii - i + 1) * (jj - j + 1);  
			value += cnt * K;
			if(value <= V) ans = max(ans, cnt);
		}
	}
	cout << ans << endl;
}
