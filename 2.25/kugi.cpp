#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> A(5020, vector<int> (5020));
	for(int i = 0; i < m; i++) {
		int a, b, x; cin >> a >> b >> x;
		A[a][b]++;
		A[a][b+1]--;
		A[a+x+1][b]--;
		A[a+x+1][b+x+2]++;
		A[a+x+2][b+1]++;
		A[a+x+2][b+x+2]--;
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		A[i][j] += A[i-1][j-1];	 
	}	
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		A[i][j] += A[i][j-1];	 
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		A[i][j] += A[i-1][j];	 
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(A[i][j]) ans++;
		}
	}
	cout << ans << endl;
}
