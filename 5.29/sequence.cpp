#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main() {
	int q; cin >> q;	
	multiset<ll> a;
	for(int i = 0; i < q; i++) {
		int t; ll x; cin >> t >> x;
		if(t == 1) {
			a.insert(x);			
		} else if(t == 2) {
			int k; cin >> k;	
			auto iter = a.upper_bound(x); 
			while(k && iter != a.begin()) {
				iter--;	
				k--;
			}	
			if(!k) cout << *iter << endl;
			else cout << -1 << endl;
		} else {
			int k; cin >> k;	
			auto iter = a.lower_bound(x);
			--k;
			while(k && iter != a.end()) {
				--k;
				++iter;
			}
			if(!k && iter != a.end()) cout << *iter << endl;
			else cout << -1 << endl;
		}
	}
}
