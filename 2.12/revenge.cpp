#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;

struct Edge {
	ll d, t;
	Edge(ll d, ll t) : d(d), t(t) {}
};

int main() {
	int n, m; cin >> n >> m;
	vvl dist(n+1, vl(n+1));
	for(int i = 0; i < m; i++) {
		ll s, t, d, time; cin >> s >> t >> d >> time;
			
	}
}
