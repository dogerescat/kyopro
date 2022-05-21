#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;	
	int n = s.size();
	int x, y; cin >> x >> y;
	vector<int> X, Y;
	bool isx = true;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'T') {
			if(isx) X.push_back(cnt);
			else Y.push_back(cnt);
			isx = !isx;
			cnt = 0;
		} else cnt++;
	}
	const int M = 8000;
	if(isx) X.push_back(cnt);
	else Y.push_back(cnt);
	int xn = X.size();
	int yn = Y.size();
	vector<vector<bool>> dpx(xn+1, vector<bool> (2 * M + 2));
	vector<vector<bool>> dpy(yn+1, vector<bool> (2 * M + 2));
	dpx[0][M] = true;
	for(int i = 0; i < xn; i++) {
		for(int j = -M; j <= M; j++) {
			if(dpx[i][M+j]) dpx[i+1][M+j+X[i]] = true;
			if(i > 0) if(dpx[i][M+j]) dpx[i+1][M+j-X[i]] = true;
		}
	}	
	dpy[0][M] = true;
	for(int i = 0; i < yn; i++) {
		for(int j = -M; j <= M; j++) {
			if(dpy[i][M+j]) {
				dpy[i+1][M+j+Y[i]] = true;
				dpy[i+1][M+j-Y[i]] = true;
			}
		}
	}
	if(dpx[xn][x+M] && dpy[yn][y+M]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
