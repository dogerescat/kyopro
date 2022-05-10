#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main() {
	int q; cin >> q;
	int n = 1 << 20;
	vector<ll> a(n, -1);
	set<int> s;
	for(int i = 0; i < n; i++) s.insert(i);
	for(int i = 0; i < q; i++) {
		int t; ll x; cin >> t >> x;
		if(t == 1) {
			auto it = s.lower_bound(x % n);	
			if(it == s.end()) it = s.begin();
			a[*it] = x;
			s.erase(it);
		} else {
			cout << a[x % n] << endl;
		}
	}
}
