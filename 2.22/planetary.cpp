#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, k; cin >> m >> n >> k;
	vector<vector<char>> A(m+1, vector<char> (n+1));	
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> A[i][j];
	vector<vector<int>> J(m+1, vector<int> (n+1));
	vector<vector<int>> O(m+1, vector<int> (n+1));
	vector<vector<int>> I(m+1, vector<int> (n+1));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(A[i][j] == 'J') J[i][j] = 1;
			else if(A[i][j] == 'O') O[i][j] = 1;
			else I[i][j] = 1;
		}
	}
	vector<vector<vector<int>>> X(3, vector<vector<int>> (m+1, vector<int> (n+1)));
	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
		X[0][i+1][j+1] = X[0][i+1][j] + X[0][i][j+1] - X[0][i][j] + J[i][j];
		X[1][i+1][j+1] = X[1][i+1][j] + X[1][i][j+1] - X[1][i][j] + O[i][j];
		X[2][i+1][j+1] = X[2][i+1][j] + X[2][i][j+1] - X[2][i][j] + I[i][j];
	}
	for(int i = 0; i < k; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans1 = 0, ans2 = 0, ans3 = 0;
		ans1 = X[0][c][d] - X[0][a-1][d] - X[0][c][b-1] + X[0][a-1][b-1];
		ans2 = X[1][c][d] - X[1][a-1][d] - X[1][c][b-1] + X[1][a-1][b-1];
		ans3 = X[2][c][d] - X[2][a-1][d] - X[2][c][b-1] + X[2][a-1][b-1];
		cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
	}
}
