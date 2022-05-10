#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> cnt(n+1);
	vector<int> ans;
	for(int i = n; i >= 1; i--) {
		int total = 0;
		for(int j = i + i; j <= n; j+=i) {
			if(cnt[j]) total++;
		}
		if(total % 2 != a[i]) cnt[i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i : ans) {
		cout << i << ' ';	
	}
	cout << endl;
}
