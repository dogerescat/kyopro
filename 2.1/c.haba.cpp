#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

int main() {
	int r, c, sy, sx, gy, gx; cin >> r >> c >> sy >> sx >> gy >> gx;
	--sy, --sx, --gy, --gx;
	vector<vector<char>> a(r, vector<char> (c));
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> a[i][j];
	vector<vector<int>> dist(r, vector<int> (c, -1));
	queue<P> que;
	que.push(P(sy, sx));
	dist[sy][sx] = 0;
	while(!que.empty()) {
		P p = que.front();
		que.pop();
		int y = p.first, x = p.second;
		for(int k = 0; k < 4; k++) {
			int ny = y + Y[k], nx = x + X[k];
			if(dist[ny][nx] != -1 || a[ny][nx] == '#') continue;
			dist[ny][nx] = dist[y][x] + 1;	
			que.push(P(ny, nx));
		}		
	}
	cout << dist[gy][gx] << endl;
}
