#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int c = a[0];
	int cnt = 1;
	vector<int> b;
	for(int i = 1; i < n; i++) {
		if(c != a[i]) {
			cnt++;
		} else {
			b.push_back(cnt);
			cnt = 1;
		}
		c = a[i];
	}
	b.push_back(cnt);
	int m = b.size();
	int ans = 0;
	for(int i = 0; i < m; i++) {
		int total = b[i];
		if(i != 0) total += b[i-1];
		if(i != m-1) total += b[i+1];
		ans = max(ans, total);
	}
	cout << ans << endl;
}
