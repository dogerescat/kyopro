#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	ll n, W; cin >> n >> W;
	vector<ll> w(n), v(n);
	for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
	vector<vector<ll>> p(4);		
	for(int i = 0; i < 4; i++) p[i].push_back(0);
	for(int i = 0; i < n; i++) {
		p[w[i] - w[0]].push_back(v[i]);
	}
	ll ans = 0;
	for(int i = 0; i < 4; i++) sort(p[i].begin() + 1, p[i].end(), greater<ll> ());
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j < p[i].size(); j++) {
			p[i][j] += p[i][j-1];
		}
	}
	for(int i = 0; i < p[0].size(); i++) for(int j = 0; j < p[1].size(); j++) {
		for(int k = 0; k < p[2].size(); k++) for(int l = 0; l < p[3].size(); l++) {
			ll total = p[0][i] + p[1][j] + p[2][k] + p[3][l];
			ll weight = (w[0] * i) + ((w[0] + 1) * j) + ((w[0] + 2) * k) + ((w[0] + 3) * l);
			if(weight <= W) ans = max(ans, total); 
		}
	}
	cout << ans << endl;
}
