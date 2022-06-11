#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main() {
	const int N = 1048576;
	int q; cin >> q;
	set<int> s;
	for(int i = 0; i < N; i++) s.insert(i);
	vector<ll> a(N, -1);
	for(int i = 0; i < q; i++) {
		int t; ll x; cin >> t >> x;
		if(t == 1) {
			auto ite = s.lower_bound(x % N);
			if(ite == s.end()) ite = s.begin();
			a[*ite] = x;	
			s.erase(ite);
		}	else {
			cout << a[x % N] << endl;
		}
	}	
}
