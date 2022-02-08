#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> b;
	reverse(a.begin(), a.end());
	vector<int> c(n+1);
	for(int i = 1; i <= n; i++) {
		c[i] = c[i-1] + a[i-1];	
	}
	for(int i = 0; i <= n; i++) {
		b.push_back(c[i] % 360);
	}
	sort(b.begin(), b.end());
	int ans = 0;
	b.push_back(360);
	for(int i = 1; i <= n+1; i++) {
		ans = max(ans, b[i] - b[i-1]);
	}
	cout << ans << endl;
}
