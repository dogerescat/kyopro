#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	bool zero_exist = false;
	int cnt = 0;
	int m = INF;
	ll total = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) zero_exist = true;	
		else if(a[i] > 0) cnt++;
		m = min(m, abs(a[i]));
		total += abs(a[i]);
	}
	if(cnt % 2 == n % 2 || zero_exist) cout << total << endl;
	else cout << total - 2 * m << endl;
}
