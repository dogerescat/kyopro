#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	vector<int> front(n, -1), back(n, -1);	
	for(int i = 0; i < q; i++) {
		int t, x, y; cin >> t >> x;
		--x;
		if(t == 1) {
			cin >> y;	 --y;
			front[y] = x;	
			back[x] = y;
		} else if(t == 2) {
			cin >> y; --y;
			front[y] = -1;
			back[x] = -1;
		} else {
			vector<int> ans;
			while(front[x] != -1) {
				x = front[x];	
			}
			while(x != -1) {
				ans.push_back(x);
				x = back[x];
			}
			cout << ans.size() << ' ';
			for(int i : ans) cout << i+1 << ' ';
			cout << endl;
		}
	}
}
