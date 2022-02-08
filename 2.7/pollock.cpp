#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;
const int ma = 1000005;
using ll = long long;
int main() {
	vector<ll> dp1(ma+1, INF), dp2(ma+1, INF);
	dp1[0] = 0, dp2[0] = 0;	
	for(ll i = 1; i * (i+1) * (i+2) <= ma * 6; i++) {
		ll v = i * (i+1) * (i+2) / 6;
		for(int i = 0; i <= ma-v; i++) {
			dp1[i+v] = min(dp1[i+v], dp1[i]+1);
			if(v % 2 != 0) {
				dp2[i+v] = min(dp2[i+v], dp2[i]+1);
			}	
		}
	}
	while(true) {
		int n; cin >> n;
		if(!n) break;
		cout << dp1[n] << " " << dp2[n] << endl;
	}
	return 0;
}
