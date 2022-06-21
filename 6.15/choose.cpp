#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;	
	vector<ll> x(n);
	ll X = 0;
	for(int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		x[i] = 2 * a + b;
		X -= a;
	}
	sort(x.begin(), x.end());
	int ans = 0;
	while(0 >= X) {
		X += x.back();
		x.pop_back();
		ans++;
	}
	cout << ans << endl;
}
