#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	int H, W, K; cin >> H >> W >> K;
	vector<ll> A(H);
	for(int i = 0; i < H; i++) cin >> A[i];
	vector<vector<int>> a(H, vector<int> (W+1));
	for(int i = 0; i < H; i++) {
		ll num = A[i];
		for(int j = W-1; j >= 0; j--) {
			a[i][j] = num % 10;	
			num /= 10;
		}
	}	
	ll ans = 0;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
		vector<vector<int>> b = a;
		b[i][j] = 0;
		ll total = 0;	
		bool ok = true;
		int d = 0;
		while(ok) {
			bool is_erase = false;	
			for(int l = H-1; l >= 0; l--) {
				for(int m = 0; m < W; m++) {
					if(b[l][m] != 0) continue;
					int k = 1;
					while(l-k >= 0) {
						if(b[l-k][m] != 0) {
							b[l][m] = b[l-k][m];
							b[l-k][m] = 0;
							break;
						}
						k++;
					}
				}
			}	
			int t = 0;
			for(int l = H-1; l >= 0; l--) {
				int pre = 0, cnt = 1;
				for(int m = 0; m <= W; m++) {
					if(pre == b[l][m]) cnt++;	
					else {
						if(cnt >= K && pre != 0) {
							t += b[l][m-1] * cnt;
							for(int k = 1; k <= cnt; k++) {
								b[l][m-k] = 0;
							}
							is_erase = true;
						}
						pre = b[l][m];
						cnt = 1;
					}
				}
			}
			total += t * (1 << d);
			d++;
			if(!is_erase) ok = false;
		}
		ans = max(ans, total);
	}
	cout << ans << endl;
}
