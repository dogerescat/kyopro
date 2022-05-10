#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string> s(n), t(n);
	for(int i = 0; i < n; i++) cin >> s[i] >> t[i];
	for(int i = 0; i < n; i++) {
		bool ok1 = false, ok2 = false;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(s[i] == s[j] || s[i] == t[j]) ok1 = true;	
			if(t[i] == s[j] || t[i] == t[j]) ok2 = true;
		}
		if(ok1 && ok2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
