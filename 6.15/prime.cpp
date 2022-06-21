#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
	int n, m; cin >> n >> m;
	vector<P> x;
	for(int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;	
		x.push_back(P(a, c));
		x.push_back(P(b+1, -c));
	}
	sort(x.begin(), x.end());
	ll ans = 0;
	ll money = 0;
	ll prev = 0;
	for(auto p : x) {
		if(money < m) ans += money * (p.first - prev);
		else ans += m * (p.first - prev);
		prev = p.first;
		money += p.second;	
	}
	cout << ans << endl;
}
