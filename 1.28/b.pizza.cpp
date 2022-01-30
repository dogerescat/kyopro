#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int d, n, m; cin >> d >> n >> m;
	vector<int> a;
	a.push_back(0);
	a.push_back(d);
	for(int i = 0; i < n-1; i++) {
		int b; cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		int index = lower_bound(a.begin(), a.end(), k) - a.begin();
		if(abs(k - a[index]) < abs(k - a[index-1])) ans += abs(k - a[index]);
		else ans += abs(k-a[index-1]);
	}
	cout << ans << endl;
}
