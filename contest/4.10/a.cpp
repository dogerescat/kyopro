#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	string ans;
	ans.push_back('0');
	for(int i = 0; i < 3; i++) ans.push_back(s[i]);
	cout << ans << endl;
}
