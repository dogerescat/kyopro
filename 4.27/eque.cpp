#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;		
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for(int l = 0; l <= k; l++) {
		for(int r = 0; r <= k - l; r++) {
			if(l + r > n) continue;
			int d = k - l - r;
			int now = 0;
			vector<int> s;
			for(int i = 0; i < l; i++) {
				now += a[i];
				s.push_back(a[i]);
			}
			for(int i = n-r; i < n; i++) {
				now += a[i];
				s.push_back(a[i]);
			}
			sort(s.begin(), s.end());
			for(int i = 0; i < d; i++) {
				if(i >= s.size()) break;
				if(s[i] >= 0) break;
				now -= s[i];
			}
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
}
