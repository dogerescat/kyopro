#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		ll a, s; cin >> a >> s;
		string ans = "No";	
		if(2 * a <= s) {
			ll deffer = s - 2 * a;	
			if(!(deffer & a)) ans = "Yes";
		}
		cout << ans << endl;
	} 
}
