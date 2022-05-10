#include <iostream>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int q; cin >> q;	
	multiset<ll> s;
	for(int i = 0; i < q; i++) {
		ll t, x, k; cin >> t >> x;
		if(t == 1) {
			s.insert(x);
		} else if(t == 2) {
			cin >> k;
			auto it = s.upper_bound(x);
			if(it == s.begin()) {
				cout << -1 << endl;
				continue;
			}
			--it;
			for(int j = 0; j < k; j++) {
				if(j == k-1) {
					cout << *it << endl;
					break;
				}
				if(it == s.begin()) {
					cout << -1 << endl;
					break;
				}
				--it;
			}	
		} else {
			cin >> k;
			auto it = s.lower_bound(x);
			if(it == s.end()) {
				cout << -1 << endl;
				continue;
			}
			for(int j = 0; j < k; j++) {
				if(j == k-1) {
					cout << *it << endl;
					break;
				}
				++it;
				if(it == s.end()) {
					cout << -1 << endl;
					break;
				}	
			}
		}
	}
}
