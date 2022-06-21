#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> w, r;
	for(int i = 0; i < n; i++) if(s[i] == 'W') w.push_back(i);
	for(int i = n-1; i >= 0; --i) if(s[i] == 'R') r.push_back(i);
	int m = min(w.size(), r.size());
	int ans = 0;
	for(int i = 0; i < m; i++) {
		if(w[i] > r[i]) break;
		ans++;
	}
	cout << ans << endl;
}
