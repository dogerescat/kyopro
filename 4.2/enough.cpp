#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	int right = 0;
	ll total = 0;
	for(int left = 0; left < n; left++) {
		while(right < n && total + a[right] < k) {
			total += a[right];	
			right++;
		}
		ans += n - right;
		if(left == right) right++;
		else total -= a[left];
	}
	cout << ans << endl;
}
