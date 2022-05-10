#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
	vector<string> s(3);
	for(ll i = 0; i < 3; i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}
	map<char, ll> mp;
	for(ll i = 0; i < 3; i++) {
		for(char i : s[i]) {
			mp[i] = 0;
		}
	}
	if(mp.size() > 10) {
		cout << "UNSOLVABLE" << endl;
		return 0;
	}
	vector<ll> num(10);	
	iota(num.begin(), num.end(), 0);
	ll a = s[0].size();
	ll b = s[1].size();
	ll c = s[2].size();
	if(a > c || b > c) {
		cout << "UNSOLVABLE" << endl;
		return 0;
	}
	do {
		ll i = 0;
		for(auto &m : mp) {
			m.second = num[i];	
			i++;
		}	
		ll add = 0;	
		ll n = max(a, b);
		bool ok = true;
		for(ll i = 0; i < n; i++) {
			ll x = add;	
			if(a > i) x += mp[s[0][i]];
			if(b > i) x += mp[s[1][i]];
			add = x / 10;
			x %= 10;
			if(mp[s[2][i]] != x) ok = false; 
		}
		if(mp[s[0][a-1]] == 0 || mp[s[1][b-1]] == 0 || mp[s[2][c-1]] == 0) ok = false;
		if(ok) {
			ll ans1 = 0, ans2 = 0, ans3 = 0;
			for(ll i = a-1; i >= 0; i--) {
				ans1 = ans1 * 10 + mp[s[0][i]];	
			}
			for(ll i = b-1; i >= 0; i--) {
				ans2 = ans2 * 10 + mp[s[1][i]];	
			}
			for(ll i = c-1; i >= 0; i--) {
				ans3 = ans3 * 10 + mp[s[2][i]];	
			}
			if(ans1 + ans2 == ans3) {
				cout << ans1 << endl;
				cout << ans2 << endl;
				cout << ans3 << endl;
				return 0;
			}
		}
	} while(next_permutation(num.begin(), num.end()));
	cout << "UNSOLVABLE" << endl;
}
