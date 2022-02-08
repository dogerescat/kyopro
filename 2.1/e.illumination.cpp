#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;
vector<int> EX = {0, 1, 0, -1, -1, -1};
vector<int> EY = {1, 0, -1, 1, 0, -1};
vector<int> OX = {1, 1, 1, 0, -1, 0};
vector<int> OY = {-1, 0, 1, 1, 0, -1};

int main() {
	int h, w; cin >> w >> h;
	vector<vector<int>> a(h+2, vector<int> (w+2));
	for(int i = 1; i <= h; i++)	for(int j = 1; j <= w; j++) cin >> a[i][j];
	queue<P> que;	
	vector<vector<int>> seen(h+2, vector<int> (w+2, -1));
	seen[0][0] = 1;
	que.push(P(0, 0));
	int ans = 0;
	while(!que.empty()) {
		P p = que.front(); que.pop();
		int y = p.first, x = p.second;
		vector<int> X, Y;
		if(y % 2 == 0) X = EX, Y = EY;
		else X = OX, Y = OY;
		for(int k = 0; k < 6; k++) {
			int ny = y + Y[k], nx = x + X[k];
			if(ny < 0 || nx < 0 || ny > h+1 || nx > w+1) continue;
			if(seen[ny][nx] != -1) continue;
			if(a[ny][nx]) {
				ans++;
				continue;
			} 
			seen[ny][nx] = 1;
			que.push(P(ny, nx));
		}
	}
	cout << ans << endl;
}
