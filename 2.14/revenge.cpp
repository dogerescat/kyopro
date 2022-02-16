#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P; 
typedef vector<P> vp;
typedef vector<vector<P>> vvp;
const ll INF = 1e16;

struct Edge {
	ll d, time;
};
typedef vector<vector<Edge>> Graph;

P f(Graph &G, vvp &dp, ll &n, ll S, ll v) {
	if(S == 0) {
		if(v == 0) return P(0, 1);
		else return P(INF, 0);
	}	
	if(!(S & (1 << v))) return P(INF, 0); 
	if(dp[S][v].first) return dp[S][v];
	P res = P(INF, 0);
	for(int i = 0; i < n; i++) {
		P p = f(G, dp, n, S ^ (1 << v), i);
		p.first += G[i][v].d;
		if(p.first <= G[i][v].time) {
			if(res.first > p.first) {
				res = p;
			} else if(res.first == p.first) {
				res.second += p.second;
			}
		}
	}
	return dp[S][v] = res; 
}
int main() {
	ll n, m; cin >> n >> m;
	Graph G(16, vector<Edge>(16));
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {
			G[i][j].d = INF;
			G[i][j].time = 0;
		}
	}
	for(int i = 0; i < m; i++) {
		ll a, b, d, t; cin >> a >> b >> d >> t;	
		--a, --b;
		G[a][b].d = d;
		G[a][b].time = t;
		G[b][a].d = d;
		G[b][a].time = t;
	}
	vvp dp((1<<16), vp(16));
	P ans = f(G, dp, n, (1 << n)-1, 0);
	if(ans.first != INF) cout << ans.first << " " << ans.second << endl;	
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}
