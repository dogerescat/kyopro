#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int left = 0, right = 0;
	string ans1, ans2;
	for(int i = 0; i < n; i++) {
		if(s[i] == ')') {
			right++;
			if(left < right) {
				ans1.push_back('(');
				left++;
			}
		} else {
			left++;
		}
	}
	left = 0; right = 0;
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '(') {
			left++;
			if(left > right) {
				ans2.push_back(')');
				right++;
			}
		} else {
			right++;
		}
	}
	cout << ans1 << s << ans2 << endl;
}
