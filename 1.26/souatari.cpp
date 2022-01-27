#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; i++) cin >> b[i];
	vector<bool> ans(m);
	for(int bit = 0; bit < 1 << n; bit++) {
		int total = 0;
		for(int i = 0; i < n; i++) {
			if(bit & 1 << i) total += a[i];
		}
		for(int i = 0; i < m; i++) if(total == b[i]) {
			ans[i] = true;
		}
	}
	for(int i = 0; i < m; i++) {
		if(ans[i]) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
