#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;
template<class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}

int main() {
	int a, b, q; cin >>  a >> b >> q;
	vector<ll> s(a), t(b);
	for(int i = 0; i < a; i++) cin >> s[i];
	for(int i = 0; i < b; i++) cin >> t[i];
	for(int i = 0; i < q; i++) {
		ll x; cin >> x;
		ll ans = INF;
		auto sr = upper_bound(s.begin(), s.end(), x);
		auto tr = upper_bound(t.begin(), t.end(), x);
		int sl = sr - s.begin();
		int tl = tr - t.begin();
		if(sl != 0) sl--;
		if(tl != 0) tl--;
		if(sr != s.end() && tr != t.end()) chmin(ans, max(*sr, *tr) - x);
		if(sr != s.end() && tr != t.begin()) {
			ll absl = abs(x-t[tl]);
			ll absr = abs(x-*sr);	
			chmin(ans, 2 * min(absl, absr) + max(absl, absr));
		}
		if(tr != t.end() && sr != s.begin()) {
			ll absl = abs(x-s[sl]);
			ll absr = abs(x-*tr);
			chmin(ans, 2 * min(absl, absr) + max(absl, absr));
		}
		if(*sr != s[sl] && *tr != t[tl]) chmin(ans, x - min(s[sl], t[tl]));
		cout << ans << endl;
	}
}
