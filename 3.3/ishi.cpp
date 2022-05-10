#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int H, W, K; cin >> H >> W >> K;
	vector<string> s(H);
	for(int i = 0; i < H; i++) cin >> s[i];
	vector<vector<int>> a(H, vector<int>(W+1));
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
		a[i][j] = s[i][j] - '0';
	}
	int ans = 0;
	for(int h = 0; h < H; h++) for(int w = 0; w < W; w++) {
		vector<vector<int>> b = a;
		bool ok = true;
		b[h][w] = 0;
		int d = 0;
		int total = 0;
		while(ok) {
			bool is_erase = false;
			for(int i = H-1; i >= 0; i--) for(int j = 0; j < W; j++) {
				if(b[i][j] != 0) continue;		
				int k = 1;
				while(i - k >= 0) {
					if(b[i-k][j] != 0) {
						b[i][j] = b[i-k][j];
						b[i-k][j] = 0;
						break;
					}
					k++;
				}
			}
			int t = 0;
			for(int i = H-1; i >= 0; i--) {
				int pre = 0, cnt = 1;
				for(int j = 0; j <= W; j++) {
					if(pre == b[i][j]) cnt++;
					else {
						if(cnt >= K && pre != 0) {
							t += b[i][j-1] * cnt;
							for(int k = 1; k <= cnt; k++) {
								b[i][j-k] = 0;
							}
							is_erase = true;
						}
						cnt = 1;
						pre = b[i][j];
					}
				}
			}
			total += (1 << d) * t;
			d++;
			if(!is_erase) ok = false;
		}
		ans = max(ans, total);
	}
	cout << ans << endl;
}
