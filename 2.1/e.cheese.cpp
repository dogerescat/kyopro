#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

int main() {
	int h, w, n; cin >> h >> w >> n;
	vector<vector<char>> a(h+2, vector<char> (w+2, 'X'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<P> p(n+1);
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
		if(a[i][j] == 'X' || a[i][j] == '.') continue;	
		if(a[i][j] == 'S') p[0] = P(i, j);
		else {
			int k = a[i][j] - '0';
			p[k] = P(i, j);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		vector<vector<int>> dist(h+2, vector<int> (w+2, -1));
		queue<P> que;
		int sy = p[i].first, sx = p[i].second;
		dist[sy][sx] = 0;	
		que.push(P(sy, sx));
		while(!que.empty()) {
			P p = que.front(); que.pop();
			int y = p.first, x = p.second;
			for(int k = 0; k < 4; k++) {
				int ny = y + Y[k], nx = x + X[k];	
				if(a[ny][nx] == 'X' || dist[ny][nx] != -1) continue;
				dist[ny][nx] = dist[y][x] + 1;	
				que.push(P(ny, nx));
			}
		}
		ans += dist[p[i+1].first][p[i+1].second];
	}
	cout << ans << endl;
}
