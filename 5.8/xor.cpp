#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n+1);
	vector<ll> x(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];	
		x[i] = a[i] ^ x[i-1];
		a[i] += a[i-1];
	}	
	int right = 1;
	ll ans = 0;
	for(int left = 1; left <= n; left++) {
		while(right <= n && (a[right]-a[left-1]) == (x[right]^x[left-1])) {
			right++;	
		}
		ans += right - left;
		if(right == left) right++;
	}
	cout << ans << endl;
}
