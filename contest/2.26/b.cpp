#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	map<int, int> mp;	
	for(int i = 0; i < n; i++) {
		int a; cin >> a;	
		mp[a]++;
	}
	vector<int> b(m);
	for(int i = 0; i < m; i++) cin >> b[i];
	for(int i = 0; i < m; i++) {
		if(mp[b[i]] > 0) mp[b[i]]--;	
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
