#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n; 
	vector<int> A(n), B(n), C(n);
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) cin >> B[i];
	for(int i = 0; i < n; i++) cin >> C[i];
	sort(A.begin(), A.end());
	sort(C.begin(), C.end());
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int ai = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
		int ci = n - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
		ans += (ll)ai * ci;
	}	
	cout << ans << endl;
}
