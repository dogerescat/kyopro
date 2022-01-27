#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n; string s; cin >> n >> s;
	int ans = 0;
	for(int i = 0; i <= 999; i++) {
		string t; 
		int p = i;
		for(int j = 0; j < 3; j++) {
			t += '0' + (p % 10); 
			p /= 10;
		}
		int ti = 0;
		for(int j = 0; j < n; j++) {
			if(s[j] == t[ti]) {
				ti++;
				if(ti == 3) break;
			}	
		}
		if(ti == 3) ans++;
	}	
	cout << ans << endl;
}
