#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MX = 1000001;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> s(MX);
	for(int i = 0; i < n; i++) {
		int x = a[i];	
		if(s[a[i]] != 0) {
			s[a[i]] = 2;
			continue;
		}
		while(x <= MX) {
			s[x]++;
			x += a[i];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[a[i]] == 1) ans++;
	}
	cout << ans << endl;
}
