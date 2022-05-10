#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll M = 1e18;
int main() {
	int n; ll x; cin >> n >> x;	
	string s; cin >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'U' && x != 1) x /= 2;
		else if(s[i] == 'L' && x <= M / 2) x = x * 2;
		else if(s[i] == 'R' && x <= M / 2) x = x * 2 + 1;
	}
	cout << x << endl;
}
