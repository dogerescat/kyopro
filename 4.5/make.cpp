#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> P;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<int>> a(h+2, vector<int> (w+2));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<P> ans;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j < w; j++) {
			if(a[i][j] % 2 == 1) {
				a[i][j+1]++;
				a[i][j]--;
				ans.push_back(P(make_pair(i, j), make_pair(i, j+1)));
			}	
		}
	}
	for(int i = 1; i < h; i++) {
		if(a[i][w] % 2 == 1) {
			a[i][w]--;
			a[i+1][w]++;
			ans.push_back(P(make_pair(i, w), make_pair(i+1, w)));
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		int x1 = ans[i].first.first;	
		int y1 = ans[i].first.second;
		int x2 = ans[i].second.first;
		int y2 = ans[i].second.second;
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	}
}
