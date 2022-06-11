#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
using ll = long long;

ll sum(string s) {
	vector<ll> cnt(10);
	iota(cnt.begin(), cnt.end(), 0);
	for(char c : s) cnt[c - '0'] *= 10;
	return accumulate(cnt.begin(), cnt.end(), 0);
}

int main() {
	int k; string s, t; cin >> k >> s >> t;
	vector<ll> a(10, k);
	for(int i = 0; i < 4; i++) {
		a[s[i] - '0']--;
		a[t[i] - '0']--;
	}
	ll win = 0;
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			s.back() = i + '0';	
			t.back() = j + '0';
			if(sum(s) <= sum(t)) continue; 
			win += a[i] * (a[j] - (i == j));
		}
	}
	ll total = 9 * k - 8;
	cout << (double) win / total / (total-1) << endl;
}
