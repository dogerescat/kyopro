#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<ll, int> P;

int main() {
	int n, K; cin >> n >> K;
	vector<ll> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector<P> xp;
	for(int i = 0; i < n; i++) xp.push_back(P(x[i], i));
	sort(xp.begin(), xp.end());
	ll ans = 1LL << 62;
	for(int xi = 0; xi < n; xi++) {
		for(int xj = xi+1; xj < n; xj++) {
			vector<P> yp;
			if(xj - xi + 1 < K) continue;
			for(int k = xi; k <= xj; k++) yp.push_back(P(y[xp[k].second], xp[k].second));
			sort(yp.begin(), yp.end());
			int m = yp.size();
			for(int yi = 0; yi < m; yi++) {
				for(int yj = yi+1; yj < m; yj++) {
					int cnt = yj - yi + 1;			
					if(cnt >= K) ans = min(ans, (ll)(xp[xj].first - xp[xi].first) * (yp[yj].first - yp[yi].first));
				}
			}
		}
	}
	cout << ans << endl;
}
