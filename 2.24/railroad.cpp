#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, m; cin >> n >> m;
	vector<int> P(m);
	vector<ll> A(n), B(n), C(n);
	for(int i = 0; i < m; i++) cin >> P[i];
	for(int i = 1; i < n; i++) cin >> A[i] >> B[i] >> C[i];
	vector<ll> sum(n+1);
	for(int i = 1; i < m; i++) {
		int a = P[i-1], b = P[i];
		if(a > b) swap(a, b);
		sum[a]++;
		sum[b]--;
	}
	for(int i = 1; i <= n; i++) sum[i] += sum[i-1];
	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ans += min(A[i]*sum[i], B[i]*sum[i]+C[i]);
	}
	cout << ans << endl;
}
