#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s; int k; cin >> s >> k;	
	int right = 0;
	int cnt = 0;
	int ans = 0;
	for(int left = 0; left < s.size(); left++) {
		while(right < s.size() && (cnt < k || s[right] == 'X')) {
			if(s[right] == '.') cnt++;
			right++;
		}
		ans = max(ans, right - left);
		if(right == left) right++;
		if(s[left] == '.' && cnt > 0) cnt--;
	}
	cout << ans << endl;
}
