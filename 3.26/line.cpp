#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x, y; cin >> n >> x >> y;
	vector<int> ans(n);
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			int k = j - i;	
			k = min(k, abs(i - x) + abs(j - y) + 1);
			ans[k]++;
		}
	}
	for(int i = 1; i < n; i++) {
		cout << ans[i] << endl;
	}
}
