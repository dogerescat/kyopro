#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int M = 2019;

int main() {
	string s; cin >> s;	
	int n = s.size();
	reverse(s.begin(), s.end());
	vector<int> cnt(M);
	int x = 1, total = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cnt[total]++;
		total += (s[i] - '0') * x;
		total %= M;
		ans += cnt[total];
		x = x * 10 % M;	
	}
	cout << ans << endl;
}
