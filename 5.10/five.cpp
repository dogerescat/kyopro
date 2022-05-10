#include <iostream>
#include <vector>
using namespace std;
vector<bool> eratos() {
	vector<bool> res(100001, true);
	res[0] = res[1] = false;
	for(int i = 2; i < 100001; i++) {
		int j = 2;
		while(i * j < 100001) {
			res[i * j] = false;
			j++;
		}
	}
	return res;
}

int main() {
	int n; cin >> n;
	vector<int> p;
	vector<bool> res = eratos();
	for(int i = 0; i < 100001; i++) if(res[i]) p.push_back(i);
	vector<int> ans;
	int cnt = 0;
	for(int i : p) {
		if(cnt == n) break;
		if(i % 5 == 1) {
			ans.push_back(i);
			cnt++;
		}
	}
	for(int i : ans) cout << i << ' ';
	cout << endl;
}
