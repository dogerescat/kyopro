#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> s(n);
	for(int i = 0; i < n; i++) {
		s[a[i]-1].push_back(i);
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int l, r, x; cin >> l >> r >> x;
		--l, --r, --x;	
		int left = lower_bound(s[x].begin(), s[x].end(), l) - s[x].begin();
		int right = upper_bound(s[x].begin(), s[x].end(), r) - s[x].begin();
		if(left == s[x].size()) {
			cout << 0 << endl;
		} else {
			cout << right - left << endl;
		}
	}
}
