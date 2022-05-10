#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
	int n, m; cin >> n >> m;	
	vector<ll> H(n), W(m);
	for(int i = 0; i < n; i++) cin >> H[i];
	for(int i = 0; i < m; i++) cin >> W[i];
	sort(H.begin(), H.end());	
	W.push_back(-INF);
	W.push_back(INF);
	sort(W.begin(), W.end());
	vector<ll> ds(n), dt(n);
	{
		ll now = 0;
		for(int i = 0; i < n; i++) {
			if(i % 2 == 1) now += abs(H[i] - H[i-1]);
			ds[i] = now;
		}
	}
	{
		ll now = 0;
		for(int i = 0; i < n; i++) {
			int ni = n - 1 - i;
			if(i % 2 == 1) now += abs(H[ni] - H[ni+1]);
			dt[ni] = now;
		}
	}	
	ll ans = INF;
	for(int i = 0; i < n; i++) {
		if(i % 2 == 1) continue;
		ll now = 0;
		{
			int j = lower_bound(W.begin(), W.end(), H[i]) - W.begin();
			now += min(W[j]-H[i], H[i] - W[j-1]);
		}
		now += ds[i] + dt[i];	
		ans = min(ans, now);
	}
	cout << ans << endl;
}
