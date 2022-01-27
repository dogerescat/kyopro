#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<char>> a(8, vector<char>(8, '.'));
	for(int i = 0; i < n; i++) {
		int r, c; cin >> r >> c;
		a[r][c]	= 'Q';
	}
	vector<int> num(8);
	iota(num.begin(), num.end(), 0);
	do {
		vector<vector<char>> b = a;
		bool ok = true;
		for(int i = 0; i < 8; i++) {
			b[i][num[i]] = 'Q';
		}
		for(int i = 0; i < 8; i++) {
			int cnt1 = 0;
			int cnt2 = 0;
			for(int j = 0; j < 8; j++) {
				if(b[i][j] == 'Q') cnt1++;	
				if(b[j][i] == 'Q') cnt2++;
			}
			if(cnt1 != 1 || cnt2 != 1) ok = false;
		}
		if(!ok) continue;
		for(int i = 0; i < 8; i++) {
			int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
			int k = i, j = 0;
			while(k >= 0) {
				if(b[k][j] == 'Q') cnt1++;
				if(b[7-k][7-j] == 'Q') cnt2++;
				if(b[7-k][j] == 'Q') cnt3++;
				if(b[k][7-j] == 'Q') cnt4++;
				k--;
				j++;
			}
			if(cnt1 > 1 || cnt2 > 1 || cnt3 > 1 || cnt4 > 1) ok = false;
		}
		if(ok) {
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					cout << b[i][j];
				}
				cout << endl;
			}
			return 0;
		}	
	} while(next_permutation(num.begin(), num.end()));
	
}
