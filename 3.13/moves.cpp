#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int n; ll x; cin >> n >> x;
	string s; cin >> s;
	stack<char> st;
	string S;
	st.push(s[0]);
	for(int i = 1; i < n; i++) {
		if(st.empty()) {
			st.push(s[i]);
			continue;
		}
		char v = st.top();	
		if(v == 'L' || v == 'R') {	
			if(s[i] == 'U') {
				st.pop();
			} else st.push(s[i]);
		} else st.push(s[i]);
	}
	while(!st.empty()) {
		char v = st.top(); st.pop();
		S.push_back(v);
	}
	reverse(S.begin(), S.end());
	for(auto c : S) {
		if(c == 'U' && x != 1) x /= 2;
		else if(c == 'L') x = x * 2;
		else if(c == 'R') x = x * 2 + 1;
	}
	cout << x << endl;
}
