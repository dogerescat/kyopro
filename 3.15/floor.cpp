#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;	
	int n = s.size();
	vector<int> a(n+1);
	for(int i = n; i >= 1; i--) {
		a[n-i+1] = s[i-1] - '0';
	}
	for(int i = 1; i <= n; i++) {
		a[i] = a[i-1] + a[i];
	}
	string ans;	
	int up = 0;
	for(int i = 0; i < n; i++) {
		int w = a[n] - a[i] + up;	
		ans.push_back((w%10)+'0');
		up = w / 10;
	}
	while(up) {
		ans.push_back((up%10)+'0');
		up /= 10;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
