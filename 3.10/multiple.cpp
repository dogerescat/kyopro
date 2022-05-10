#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int INF = 1001001001;

int main() {	
	int a, n;
	cin >> a >> n;
	const int M = 1000000;
	vector<int> dist(M, INF);
	queue<int> que;
	auto push = [&](int v, int d) {
		if(dist[v] != INF) return;
		dist[v] = d;
		que.push(v);
	};
	push(1, 0);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v];
		if((long long)v*a < M) push(v*a, d+1);
		if(v >= 10 && v % 10 != 0) {
			string s = to_string(v);
			int len = s.size();
			rotate(s.begin(), s.begin()+(len-1), s.end());
			int u = stoi(s);
			push(u, d+1);
		}
	}
	if(dist[n] == INF) cout << -1 << endl;
	else cout << dist[n] << endl;
}
