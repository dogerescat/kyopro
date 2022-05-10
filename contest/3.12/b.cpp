#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	set<int> as, bs;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == b[i]) {
			ans1++;	
			continue;
		}
		if(as.count(b[i])) ans2++;
		if(bs.count(a[i])) ans2++;
		as.insert(a[i]);
		bs.insert(b[i]);
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
}
