#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans1 = a[n-1];
	int x = a[n-1] / 2;
	int y = 1001001001;
	int ans2 = 0;
	for(int i = 0; i < n-1; i++) {
		if(y >= abs(x - a[i])) {
			ans2 = a[i];	
			y = abs(x - a[i]);
		}	
	}	
	cout << ans1 << ' ' << ans2 << endl;
}
