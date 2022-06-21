#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<int> a(10);
	for(int i = 0; i < n; i++) a[s[i] - '0']++;
	for(int i = 8; i < 1000; i+= 8) {
		string t = to_string(i);
		int m = t.size();
		if(m < 3 && n != m) continue; 
		vector<int> b = a;
		for(int j = 0; j < m; j++) {
			b[t[j] - '0']--;
		}
		bool ok = true;
		for(int j = 0; j <= 9; j++) if(b[j] < 0) ok = false;
		if(ok) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
