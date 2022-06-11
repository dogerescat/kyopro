#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, d; cin >> n >> d;
	vector<P> a(n);
	for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end());
	int ans = 0;
	int pre = 0;
	for(int i = 0; i < n; i++) {
		if(pre >= a[i].second) continue; 	
		ans++;
		pre = a[i].first + d - 1;
	}
	cout << ans << endl;
}
