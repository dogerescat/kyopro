#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	int a, b; ll k; cin >> a >> b >> k;	
	vector<vector<ll>> c(61, vector<ll>(61));
	c[0][0] = 1;
	for(int i = 0; i < 60; i++) {
		for(int j = 0; j < i+1; j++) {
			c[i+1][j] += c[i][j];	
			c[i+1][j+1] += c[i][j];
		} 
	}
	string ans;
	while(a + b > 0) {
		ll x = 0;
		if(a > 0) x = c[a+b-1][a-1];
		if(k <= x) {
			ans.push_back('a');
			--a;
		} else {
			ans.push_back('b');
			--b;
			k -= x;
		}
	}
	cout << ans << endl;
}
