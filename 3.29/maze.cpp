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
	vector<vector<char>> A(h+2, vector<char>(w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> A[i][j];
	int ans = 0;
	for(int si = 1; si <= h; si++) for(int sj = 1; sj <= w; sj++) {
		if(A[si][sj] == '#') continue;
		vector<vector<int>> dist(h+2, vector<int> (w+2, -1));
		queue<P> que;			
		dist[si][sj] = 0;
		que.push(P(si, sj));
		while(!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			for(int k = 0; k < 4; k++) {
				int ni = y + dy[k];
				int nj = x + dx[k];
				if(A[ni][nj] == '#') continue;
				if(dist[ni][nj] != -1) continue;
				dist[ni][nj] = dist[y][x] + 1; 
				que.push(P(ni, nj));
			}
		}
		for(int ti = 1; ti <= h; ti++) for(int tj = 1; tj <= w; tj++) {
			if(A[ti][tj] == '#') continue;	
			ans = max(ans, dist[ti][tj]);		
		}
	}
	cout << ans << endl;
}
