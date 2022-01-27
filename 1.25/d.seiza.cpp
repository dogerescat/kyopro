#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> P;
int main() {
	int m, n; cin >> m;
	vector<P> a(m);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
	}
	cin >> n;
	set<P> b;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		b.insert(P(x, y));
	}
	for(auto i : b) {
		bool ok = true;
		for(int j = 1; j < m; j++) {
			int x = a[j].first - a[0].first;	
			int y = a[j].second - a[0].second;
			if(!b.count(P(i.first+x, i.second+y))) ok = false;
		}
		if(ok) {
			cout << i.first - a[0].first << ' ' << i.second - a[0].second << endl;
			return 0;
		}
	}
}
