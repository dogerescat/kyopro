#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int H = 3600;
const int M = 60;
const int MAX = 24 * 60 * 60;
int main() {
	while(true) {
		int n; cin >> n;
		if(!n) break;
		vector<int> time(MAX);
		for(int i = 0; i < n; i++) {
			string S, T; cin >> S >> T;
			int sh = 0, sm = 0, ss = 0;
			sh = sh * 10 + (S[0] - '0');			
			sh = sh * 10 + (S[1] - '0');
			sm = sm * 10 + (S[3] - '0');
			sm = sm * 10 + (S[4] - '0');
			ss = ss * 10 + (S[6] - '0');
			ss = ss * 10 + (S[7] - '0');
			time[sh * H + sm * M + ss]++;	
			int th = 0, tm = 0, ts = 0;
			th = th * 10 + (T[0] - '0');			
			th = th * 10 + (T[1] - '0');
			tm = tm * 10 + (T[3] - '0');
			tm = tm * 10 + (T[4] - '0');
			ts = ts * 10 + (T[6] - '0');
			ts = ts * 10 + (T[7] - '0');
			time[th * H + tm * M + ts]--;
		}	
		for(int i = 1; i < MAX; i++) {
			time[i] += time[i-1];
		}
		int ans = 0;
		for(int i = 0; i < MAX; i++) {
			ans = max(ans, time[i]);
		}
		cout << ans << endl;
	}
}
