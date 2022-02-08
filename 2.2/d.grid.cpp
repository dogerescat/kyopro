#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h+2, vector<char> (w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	int cnt = 0;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
		if(a[i][j] == '.') cnt++;
	}
	queue<P> que;
	vector<vector<int>> dist(h+2, vector<int> (w+2, -1));
	que.push(P(1, 1));
	dist[1][1] = 0;
	while(!que.empty()) {
		P p = que.front(); que.pop();
		int y = p.first, x = p.second;
		for(int k = 0; k < 4; k++) {
			int ny = y + Y[k], nx = x + X[k];
			if(dist[ny][nx] != -1 || a[ny][nx] == '#') continue;
			dist[ny][nx] = dist[y][x] + 1;
			que.push(P(ny, nx));
		}
	}
	if(dist[h][w] == -1) cout << -1 << endl;
	else cout << cnt - dist[h][w] - 1 << endl;
}
