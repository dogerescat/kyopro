#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	int k = 1;
	while(1) {
		if(k *(k-1) == 2 * n) break;
		else if(k * (k-1) > 2 * n) {
			cout << "No" << endl;
			return 0;
		} else k++;
	}
	cout << "Yes" << endl;
	vector<vector<int>> a(k+1);
	int id = 1;
	int tmpid = 0;
	for(int i = 1; i <= n; i++) {
		a[id].push_back(i);
		a[tmpid].push_back(i);
		tmpid++;
		if(tmpid == id) {
			id++;
			tmpid = 0;
		}
	}	
	cout << k << endl;
	for(int i = 0; i < k; i++) {
		cout << a[i].size() << ' ';
		for(int j = 0; j < k-1; j++) {
			cout << a[i][j] << ' ';	
		}
		cout << endl;
	}	
}
