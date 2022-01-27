#include <iostream>
#include <string> 
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	vector<string> t(m);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < m; i++) cin >> t[i];
	set<string> ss;
	for(int i = 0; i < m; i++) ss.insert(t[i]);
	for(int i = 0; i < n; i++) {
		if(ss.count(s[i])) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
