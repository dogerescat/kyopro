#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
	int n; cin >> n;
	vector<ll> h(n), s(n);	
	for(int i = 0; i < n; i++) cin >> h[i] >> s[i];
	ll left = -1, right = INF;	
	while(right - left > 1) {
		ll mid = (right + left) / 2;
		bool ok = true;
		vector<ll> t(n);
		for(int i = 0; i < n; i++) {
			if(mid < h[i]) ok = false;
			else t[i] = (mid - h[i]) / s[i];	
		}
		sort(t.begin(), t.end());
		for(int i = 0; i < n; i++) {
			if(t[i] < i) ok = false; 
		}
		if(ok) right = mid;
		else left = mid;
	}
	cout << right << endl;
}
