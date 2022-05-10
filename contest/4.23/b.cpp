#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string s; cin >> s;
	bool flag1 = false, flag2 = false, flag3 = false;
	set<char> c;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] >= 'a' && s[i] <= 'z') flag1 = true;
		else if(s[i] >= 'A' && s[i] <= 'Z') flag2 = true;
		c.insert(s[i]);
	}
	if(c.size() == n) flag3 = true;
	if(flag1 && flag2 && flag3) cout << "Yes" << endl;
	else cout << "No" << endl;
}
