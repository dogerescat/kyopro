#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	int ok = true;
	for(int i = 0; i < n; i++) {
		if(s[i] != s[n-1-i]) ok = false;
	}
	if(ok) {
		cout << "Yes" << endl;
		return 0;
	}
	int index = 0;
	while(s.back() == 'a') {
		s.pop_back();
		if(s[index] == 'a') index++;
		
	}
	ok = true;
	string ss = s.substr(index);
	int m = ss.size();
	for(int i = 0; i < m; i++) {
		if(ss[i] != ss[m-1-i]) ok = false;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
