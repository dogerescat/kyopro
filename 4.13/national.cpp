#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	int h, w; ll c; cin >> h >> w >> c;
	vector<vector<int>> a(h, vector<int> (w));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
	ll ans = INF;
	for(int k = 0; k < 2; k++) {
		vector<vector<ll>> d(h, vector<ll> (w, INF));
		for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
			if(i) d[i][j] = min(d[i][j], d[i-1][j]);	
			if(j) d[i][j] = min(d[i][j], d[i][j-1]);
			ans = min(ans, a[i][j] + (i + j) * c + d[i][j]);
			d[i][j] = min(d[i][j], a[i][j] - (i + j) * c);
		}
		reverse(a.begin(), a.end());
	}
	cout << ans << endl;
}
