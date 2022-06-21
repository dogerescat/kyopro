#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	int n; string s; cin >> n >> s; 
	vector<int> rgb(3);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'R') rgb[0]++;
		else if(s[i] == 'G') rgb[1]++;
		else rgb[2]++;
	}
	ll total = (ll)rgb[0] * rgb[1] * rgb[2];
	ll cnt = 0;
	for(int i = 0; i < n; i++) for(int j = i+2; j < n; j+=2) {
		int k = (i + j) / 2;
		if(s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) cnt++;
	}
	cout << total - cnt << endl;
}
