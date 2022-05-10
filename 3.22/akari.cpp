#include <iostream>
#include <vector>
using namespace std;
const int MX = 1505;

int h, w; 
bool light[MX][MX];
bool wall[MX][MX];
bool ok[MX][MX];

bool visited[MX][MX];
bool memo[MX][MX];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

bool f(int v, int i, int j) {
	if(i < 0 || j < 0 || i >= h || j >= w) return false;
	if(wall[i][j]) return false;
	if(light[i][j]) return true;
	if(visited[i][j]) return memo[i][j];
	int ni = i + dy[v], nj = j + dx[v];
	visited[i][j] = true;
	return memo[i][j] = f(v, ni, nj);
}
int main() {
	cin >> h >> w;
	int n, m; cin >> n >> m;	
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		light[a][b] = true;
	}		
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		wall[a][b] = true;
	}
	for(int v = 0; v < 4; v++) {
		for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) visited[i][j] = false;
		for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(f(v, i, j)) ok[i][j] = true;
	}
	int ans = 0;
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(ok[i][j]) ans++;
	cout << ans << endl;
}
