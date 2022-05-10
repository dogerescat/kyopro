#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<bool> dp(k+1, true);
	dp[0] = false;
	for(int i = 1; i <= k; i++) {
		bool win = false;
		for(int j = 0; j < n; j++) {
			if(i-a[j] >= 0) {
				if(!dp[i-a[j]]) win = true;	
			}
		}
		if(!win) dp[i] = false; 
	}
	if(dp[k]) cout << "First" << endl;
	else cout << "Second" << endl;
}
