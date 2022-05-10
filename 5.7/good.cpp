#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, c; cin >> n >> c;
	vector<vector<int>> D(c, vector<int> (c));
	vector<vector<int>> C(n, vector<int>(n));
	vector<vector<int>> a(3, vector<int> (c));
	for(int i = 0; i < c; i++) for(int j = 0; j < c; j++) cin >> D[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> C[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) C[i][j]--;
	for(int i = 0; i < c; i++) {
		int x = 0, y = 0, z = 0;	
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if((j + k) % 3 == 0) x += D[C[j][k]][i];
				else if((j + k) % 3 == 1) y += D[C[j][k]][i];
				else z += D[C[j][k]][i];
			}
		}
		a[0][i] = x;
		a[1][i] = y;
		a[2][i] = z;
	}
	int ans = 1001001001;
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			if(i == j) continue;
			for(int k = 0; k < c; k++) {
				if(i == k || j == k) continue;	
				int total = a[0][i] + a[1][j] + a[2][k];
				ans = min(ans, total);
			}
		}
	}
	cout << ans << endl;
}
