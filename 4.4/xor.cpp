#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll a) {
	a++;
	ll res = 0;
	for(int i = 0; i < 50; i++) {
		ll loop = 1LL << (i+1);
		ll cnt = (a / loop) * (loop / 2);	
		cnt += max(0LL, (a % loop) - (loop / 2));
		if(cnt % 2 == 1) {
			res += 1LL << i;
		}
	}
	return res;
}
int main() {
	ll a, b; cin >> a >> b;	
	ll ans = solve(b) ^ solve(a-1);
	cout << ans << endl;
}
