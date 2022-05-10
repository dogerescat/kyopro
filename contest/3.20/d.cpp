#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
	vector<char> s(3), t(3);
	for(int i = 0; i < 3; i++) cin >> s[i];
	for(int i = 0; i < 3; i++) cin >> t[i];
	set<string> st;
	string s1, s2, s3;
	s1.push_back(s[0]), s1.push_back(s[2]), s1.push_back(s[1]);
	s2.push_back(s[1]), s2.push_back(s[0]), s2.push_back(s[2]);
	s3.push_back(s[2]), s3.push_back(s[1]), s3.push_back(s[0]);
	st.insert(s1); st.insert(s2), st.insert(s3);
	string tt; tt.push_back(t[0]), tt.push_back(t[1]), tt.push_back(t[2]);	
	if(st.count(tt)) cout << "No" << endl;
	else cout << "Yes" << endl;
}
