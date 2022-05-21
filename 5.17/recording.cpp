#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, C; cin >> n >> C; 
	vector<int> s(n), t(n), c(n);
	vector<int> tt(200002), sum(200002);
	for(int i = 0; i < n; i++) cin >> s[i] >> t[i] >> c[i];
	for(int i = 1; i <= C; i++) {
		for(int j = 0; j < 200002; j++) tt[j] = 0; 		
		for(int j = 0; j < n; j++) if(i == c[j]) {
			tt[s[j]*2-1]++, tt[t[j]*2]--;
		} 
		for(int j = 1; j < 200002; j++) tt[j] += tt[j-1];
		for(int j = 0; j < 200002; j++) if(tt[j] > 0) sum[j]++;
	}
	int ans = 0;
	for(int i = 0; i < 200002; i++) ans = max(ans, sum[i]);
	cout << ans << endl;
}
