#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<char>> a(n, vector<char> (n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];	
	bool ok = false;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-5; j++) {
			int cnt1 = 0;
			int cnt2 = 0;
			for(int k = 0; k < 6; k++) {
				if(a[i][j+k] == '#') cnt1++;
				if(a[j+k][i] == '#') cnt2++;	
			}
			if(cnt1 >= 4 || cnt2 >= 4) ok = true; 
		}	
	}
	for(int i = 0; i < n-5; i++) {
		for(int j = 0; j < n-5; j++) {
			int cnt1 = 0;
			int cnt2 = 0;
			for(int k = 0; k < 6; k++) {
				if(a[i+k][j+k] == '#') cnt1++;
				if(a[i+k][j+5-k] == '#') cnt2++;
			}
			if(cnt1 >= 4 || cnt2 >= 4) ok = true;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
