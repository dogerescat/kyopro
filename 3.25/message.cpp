#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	map<int, int> mp;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += mp[i - a[i]];	
		mp[i + a[i]]++;
	}
	cout << ans << endl;
}
