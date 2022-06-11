#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> s(200010);
	int M = 0;
	for(int i = 0; i < n; i++) {
		M = max(M, a[i]);
		s[a[i]]++;
	}
	ll ans = 0;
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= M/i; j++) {
			int k = i * j;
			ans += (s[i] * s[j] * s[k]);
		}
	}	
	cout << ans << endl;
}
