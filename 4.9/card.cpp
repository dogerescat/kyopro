#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		mp[a[i]]++;
	}
	int even = 0;
	for(auto i : mp) {
		if(i.second % 2 == 0) even++;
	}
	if(even % 2 == 1) cout << mp.size() - 1 << endl;
	else cout << mp.size() << endl;
}
