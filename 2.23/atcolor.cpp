#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> a(1000001);
	for(int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		a[l]++;
		a[r+1]--;
	}
	for(int i = 1; i < 1000001; i++) a[i] += a[i-1];
	int ans = 0;
	for(int i = 0; i < 1000001; i++) ans = max(ans, a[i]);
	cout << ans << endl;
}
