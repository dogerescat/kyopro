#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
const int X[8] = {1, 0, 1, -1, 0, -1, 1, -1};
const int Y[8] = {0, 1, 1, 0, -1, -1, -1, 1 };
void dfs(Graph &a, Graph &dist, int h, int w) {
	if(dist[h][w] != -1) return;
	dist[h][w] = 1;
	for(int i = 0; i < 8; i++) {
		int ny = h + Y[i], nx = w + X[i];
		if(a[ny][nx]) dfs(a, dist, ny, nx);
	}
}

int main() {
	while(true) {
		int h, w; cin >> w >> h;
		if(h == 0 && w == 0) break;
		Graph a(h+2, vector<int> (w+2));
		for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
		Graph dist(h+2, vector<int> (w+2, -1));
		int ans = 0;			
		for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
			if(dist[i][j] != -1) continue;	
			if(a[i][j]) {
				dfs(a, dist, i, j);
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
