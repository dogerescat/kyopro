#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
const int INF = 1001001001;
int main() {
	int h, w; cin >> h >> w;
	int ch, cw, dh, dw; cin >> ch >> cw >> dh >> dw;
	vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<vector<int>> dist(h+2, vector<int> (w+2, INF));
	deque<P> que;
	dist[ch][cw] = 0;
	que.push_back(P(ch, cw));	
	while(!que.empty()) {
		int i = que.front().first;
		int j = que.front().second;
		que.pop_front();
		int d = dist[i][j];
		for(int k = 0; k < 4; k++) {
			int ni = i + dy[k];
			int nj = j + dx[k];
			if(a[ni][nj] == '#') continue;
			if(dist[ni][nj] <= d) continue;
			dist[ni][nj] = d;
			que.push_front(P(ni, nj));
		}
		for(int ei = -2; ei <= 2; ei++) {
			for(int ej = -2; ej <= 2; ej++) {
				int ni = i + ei, nj = j + ej;
				if(ni <= 0 || nj <= 0) continue;
				if(ni > h || nj > w) continue;
				if(a[ni][nj] == '#') continue;
				if(dist[ni][nj] <= d) continue;
				dist[ni][nj] = d + 1;
				que.push_back(P(ni, nj));
			}
		}
	}
	if(dist[dh][dw] == INF) cout << -1 << endl;
	else cout << dist[dh][dw] << endl;
}
