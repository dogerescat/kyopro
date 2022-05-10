#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, Q; cin >> N >> M >> Q;
	vector<vector<int>> table(N+1, vector<int> (N+1));
	vector<int> L(M), R(M);
	for(int i = 0; i < M; i++) cin >> L[i] >> R[i];
	for(int i = 0; i < M; i++) {
		table[L[i]][R[i]]++;
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			table[i][j] += table[i-1][j];
			table[i][j] += table[i][j-1];
			table[i][j] -= table[i-1][j-1];
		}
	}
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		int ans = table[r][r] - table[r][l-1] - table[l-1][r] + table[l-1][l-1];
		cout << ans << endl;
	}
}
