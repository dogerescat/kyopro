#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
ll c[61][61];

int main() {
	int a, b; ll k; cin >> a >> b >> k;
	c[0][0] = 1;
	for(int i = 0; i < 60; i++) {
		for(int j = 0; j <= i; j++) {
			c[i+1][j] += c[i][j]; 
			c[i+1][j+1] += c[i][j];
		}
	}
	string ans;
	while(a + b > 0) {
		ll t = 0;
		if(a > 0) t = c[a+b-1][a-1]; 
		else t = c[a+b-1][b];
		if(k > t) {
			ans.push_back('b');
			b--;
			k -= t;	
		} else {
			ans.push_back('a');
			a--;
		} 
	}	
	cout << ans << endl;
}
