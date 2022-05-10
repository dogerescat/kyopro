#include <iostream>
#include <deque>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main() {
	int q; cin >> q;
	deque<P> que;
	for(int i = 0; i < q; i++) {
		int t, c; cin >> t;
		if(t == 1) {
			int x; cin >> x >> c;
			que.push_back(P(x, c));
		} else {
			cin >> c;
			ll ans = 0;	
			while(c) {
				P p = que.front(); que.pop_front();
				if(c >= p.second) {
					ans += (ll)p.first * p.second;
					c -= p.second;
				} else {
					ans += (ll)p.first * c;
					p.second -= c;
					c = 0;
					que.push_front(p);	
				}
			}
			cout << ans << endl;
		}
	}
}
