#include <iostream>
#include <vector>
using namespace std;

vector<bool> prime(int n, vector<int> &a) {
	vector<bool> res(100001);
	for(int i = 0; i < n; i++) {
		for(int j = 1; j * j <= a[i]; j++) {
			if(a[i] % j) continue;
			res[j] = true;
			res[a[i]/j] = true;
		}
	}
	res[1] = false;
	return res;
}
int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<bool> p = prime(n, a);
	vector<int> ans;
	for(int i = 1; i <= m; i++) {
		bool ok = true;
		for(int j = 1; j * j <= i; j++) {
			if(i % j) continue;
			if(p[j] || p[i / j]) ok = false;	
		}
		if(ok) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i : ans) cout << i << endl;
}
