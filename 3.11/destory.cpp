#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n, d; cin >> n >> d;
	vector<P> a(n);	
	for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end());
	int ans = 0, x = -1;
	for(auto [r, l] : a) {
		if(l <= x) continue;
		ans++;
		x = r + d - 1;
	}
	cout << ans << endl;
}
