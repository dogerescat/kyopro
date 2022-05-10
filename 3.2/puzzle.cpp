#include <iostream>
#include <vector>
using namespace std;

int main() {
	while(true) {
		int n; cin >> n;
		if(!n) break;
		vector<vector<int>> a(n+2, vector<int> (7));
		for(int i = 1; i <= n; i++) for(int j = 1; j <= 5; j++) cin >> a[i][j];
		bool ok = true;
		int ans = 0;
		while(ok) {
			bool is_erase = false;
			for(int i = 1; i <= n; i++) {
				int cnt = 1, pre = 0;
				for(int j = 1; j <= 6; j++) {
					if(pre == a[i][j]) cnt++;
					else {
						if(cnt >= 3 && pre != 0) {
							ans += a[i][j-1] * cnt;
							for(int k = 1; k <= cnt; k++) {
								a[i][j - k] = 0;
							}
							is_erase = true;
						}
						pre = a[i][j];
						cnt = 1;
					}
				}
			}
			for(int i = n; i >= 1; i--) {
				for(int j = 1; j <= 5; j++) {
					if(a[i][j] != 0) continue;
					int k = 1;
					while(i-k >= 1) {
						if(a[i-k][j] != 0) {
							a[i][j] = a[i-k][j];
							a[i-k][j] = 0;
							break;
						}	
						k++;
					}
				}
			}
			if(!is_erase) ok = false;
		}
		cout << ans << endl;
	}
}
