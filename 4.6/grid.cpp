#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
	int h, w; cin >> h >> w;	
	vector<vector<char>> a(h+2, vector<char> (w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	int t = 0;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) if(a[i][j] == '.') t++;
	vector<vector<int>> dist(h+2, vector<int>(w+2, -1));
	queue<P> que;
	dist[1][1] = 0;
	que.push(P(1, 1));
	while(!que.empty()) {
		P p = que.front(); que.pop();
		int y = p.first, x = p.second;
		for(int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if(a[ny][nx] == '#') continue;
			if(dist[ny][nx] != -1) continue;
			dist[ny][nx] = dist[y][x] + 1;
			que.push(P(ny, nx));
		}
	}
	if(dist[h][w] == -1) cout << -1 << endl;
	else cout << t - dist[h][w] - 1 << endl;
}
