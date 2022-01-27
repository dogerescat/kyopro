#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	int a, b; cin >> a >> b;
	--a, --b;
	char ca = s[a], cb = s[b];
	s[a] = cb;
	s[b] = ca; 
	cout << s << endl;
}
