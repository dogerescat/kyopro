#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> A(n);
	vector<int> B(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		A[i] = a[i];
		B[i] = b[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int s = A[n/2], t = B[n/2];
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += abs(a[i] - s) + abs(a[i] - b[i]) + abs(t - b[i]);	
	}
	cout << ans << endl;
}
