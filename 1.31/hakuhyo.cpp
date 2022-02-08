#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

void dfs(Graph &G, Graph seen, int x, int y, int d, int &ans) {
	bool ok = false;	
	seen[x][y] = 1;
	for(int k = 0; k < 4; k++) {
		if(!G[x+X[k]][y+Y[k]] || seen[x+X[k]][y+Y[k]]) continue;
		ok = true;
		dfs(G, seen, x + X[k], y + Y[k], d+1, ans);
	}
	if(!ok) ans = max(ans, d);
}

int main() {
	int n, m; cin >> n >> m;
	Graph G(n+2, vector<int> (m+2));
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> G[i][j];
	Graph seen(n+2, vector<int> (m+2));
	int ans = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		if(!G[i][j]) continue;	
		dfs(G, seen, i, j, 1, ans);	
	}
	cout << ans << endl;
}
