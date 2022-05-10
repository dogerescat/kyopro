#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
using ll = long long;

ll score(string s) {
	vector<ll> cnt(10);
	iota(cnt.begin(), cnt.end(), 0);
	for(char c : s) cnt[c-'0'] *= 10;
	return accumulate(cnt.begin(), cnt.end(), 0);
}

int main() {
	ll k; cin >> k;
	string s, t; cin >> s >> t;
	vector<ll> cnt(10, k);	
	for(int i = 0; i < 4; i++) {
		cnt[s[i] - '0']--;
		cnt[t[i] - '0']--;
	}
	ll win = 0;
	for(ll i = 1; i <= 9; i++) for(ll j = 1; j <= 9; j++) {
		s.back() = i + '0';	
		t.back() = j + '0';
		if(score(s) <= score(t)) continue;
		win += cnt[i] * (cnt[j] - (i == j));
	}
	ll total = 9 * k - 8;
	cout << double (win) / total / (total - 1) << endl;
}
