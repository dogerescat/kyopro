#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> a;	
	int now = 1;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(now == s[i] - '0') cnt++;
		else {
			a.push_back(cnt);
			now = 1 - now;
			cnt = 1;
		}
	}
	a.push_back(cnt);
	if(a.size() % 2 == 0) a.push_back(0);
	int ans = 0;
	int total = 0;
	int right = 0;
	int left = 0;	
	int add = 2 * k + 1;
	for(int i = 0; i < a.size(); i+=2) {
		int nextl = i;	
		int nextr = min((int)a.size(), i + add);
		while(left < nextl) {
			total -= a[left];
			left++;
		}	
		while(right < nextr) {
			total += a[right];
			right++;
		}
		ans = max(ans, total);
	}
	cout << ans << endl;
}
