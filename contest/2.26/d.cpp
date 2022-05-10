#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
int main() {
	int q; cin >> q;
	map<ll, ll> m;
	set<P> s;
	for(int i = 0; i < q; i++) {
		int t, x, k;
		cin >> t >> x;
		if(t == 1) {
			if(m[x] > 0) s.insert(P(x, m[x]+1));
			else s.insert(P(x, 1));
			m[x]++;
		}   else if(t == 2) {
			auto ite = s.upper_bound(P(x, 1));
			auto f = s.begin();	
			while(k > 0 && f != ite) {
				k--;
				ite--;
			}
			if(k > 0) cout << -1 << endl;
			else cout << ite->first << endl;
		} else if(t == 3) {
			cin >> k;
			auto ite = s.lower_bound(P(x, 1));
			auto l = s.end();
			while(k > 0 && ite != l) {
				k--;
				ite++;
			}
			if(k > 0) cout << -1 << endl;
			else cout << ite->first << endl;
		}
	}
}
