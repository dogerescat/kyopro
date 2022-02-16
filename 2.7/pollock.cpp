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
		for(int j = 0; j <= ma-v; j++) {
			dp1[j+v] = min(dp1[j+v], dp1[j]+1);
			if(v % 2 != 0) {
				dp2[j+v] = min(dp2[j+v], dp2[j]+1);
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
