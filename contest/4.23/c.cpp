#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	int ans = 0;
	for(int bit = 0; bit < 1 << n; bit++) {
		vector<int> cnt(26);
		for(int i = 0; i < n; i++) {
			if(bit & 1 << i) for(char c : s[i]) {
				cnt[c - 'a']++;
			}	
		}
		int t = 0;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == k) t++;
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}
