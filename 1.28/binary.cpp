#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, q; cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	cin >> q;
	int ans = 0;
	for(int i = 0; i < q; i++) {
		int t; cin >> t;
		if(binary_search(s.begin(), s.end(), t)) ans++;
	}
	cout << ans << endl;
}
