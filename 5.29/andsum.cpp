#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		ll a, s; cin >> a >> s;
		string ans = "No";	
		if(2 * a <= s) {
			ll diff = s - 2 * a;
			if(!(diff & a)) ans = "Yes";
		}
		cout << ans << endl;
	}
}
