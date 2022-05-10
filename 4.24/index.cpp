#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	int n; cin >> n;
	const int M = 200005;
	vector<ll> d(M);
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		d[a]++;
	}
	ll ans = 0;
	for(int i = 1; i < M; i++) {
		for(int j = 1; j * i < M; j++) {
			int k = i * j;
			ans += d[i] * d[j] * d[k];
		}
	}
	cout << ans << endl;
}
