#include <iostream>
#include <set>
#include <string>
using namespace std;
using ll = long long;
set<ll> gen() {
	set<ll> res;
	for(int i = 1; i <= 9; i++) {
		for(int d = -9; d <= 8; d++) {
			int dg = i;
			string s;
			for(int j = 0; j < 18; j++) {
				s.push_back(dg + '0');	
				res.insert(stoll(s));
				dg += d;
				if(!(dg >= 0 && dg <= 9)) break;
			}
		}
	}
	return res;
}
int main() {
	ll x; cin >> x;
	set<ll> res = gen();		
	cout << *res.lower_bound(x) << endl;
}
