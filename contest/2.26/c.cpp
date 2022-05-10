#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<char>> a(n, vector<char>(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	bool ok = false;
	for(int k = 0; k < n; k++) {
		int cnt = 0;
		int j = 0;
		for(int i = 0; i < n; i++) {
			while(j < n && j - i < 6) {
				if(a[k][j] == '#') cnt++;				
			}	
			if(cnt >= 4) ok = true;
			if(i == j) j++;
			else {
				if(a[k][i] == '#') cnt--; 
			}
		}
	}
	for(int k = 0; k < n; k++) {
		int cnt = 0;
		int j = 0;
		for(int i = 0; i < n; i++) {
			while(j < n && j - i < 6) {
				if(a[j][k] == '#') cnt++;				
			}	
			if(cnt >= 4) ok = true;
			if(i == j) j++;
			else {
				if(a[i][k] == '#') cnt--; 
			}
		}
	}
	for(int k = 0; k < n; k++) {
		int cnt = 0;
		int l = k;
		int j = 0;
		for(int i = 0; i < n; i++) {
			while(j < n && j - i < 6) {
				if(a[l][j] == '#') cnt++;				
			}	
			if(cnt >= 4) ok = true;
			if(i == j) j++;
			else {
				if(a[l][i] == '#') cnt--; 
			}
		}
	}
}
