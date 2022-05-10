#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> b(n+1, vector<int> (3));
	for(int i = 1; i <= n; i++) {
		bool ok = false;
		for(int j = 0; j < 3; j++) {
			if(b[i-1][j] == a[i-1] && !ok) {
				b[i][j] = b[i-1][j] + 1;	
				ok = true;
			} else {
				b[i][j] = b[i-1][j];
			}	
		}
	}
	ll t = 1;
	for(int i = 0; i < n; i++) {
		ll cnt = 0;
		for(int j = 0; j < 3; j++) {
			if(a[i] == b[i][j]) cnt++;	
		}	
		t = t * cnt % MOD;
	}
	cout << t << endl;
}
