#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
		int k = 1;
		while(1) {
			if(k * (k-1) == 2 * n) break;
			else if(k * (k-1) > 2 * n) {
				cout << "No" << endl;
				return 0;
			} else k++;
		}
		vector<vector<int>> a(k+1, vector<int> (k+1));
		int t = 0;
		int prev = 1;
		for(int i = 0; i < k-1; i++) {
			for(int j = 0; j <= t; j++) {
				a[t][j] = prev;
				prev++;
			}	
			t++;
		}

		vector<vector<int>> ans;
		vector<int> b, c, d;
		for(int i = 0; i < k-1; i++) {
			b.push_back(a[i][0]);		
			c.push_back(a[k-2][i]);
			d.push_back(a[i][i]);
		}
		ans.push_back(b);
		ans.push_back(c);
		ans.push_back(d);
		int s = 1;
		for(int i = 1; i < k-1; i++) {
			int h = i;
			int w = 0;
			vector<int> e;
			e.push_back(a[h][w]);
			for(int j = 0; j < s; j++) {
				w++;
				e.push_back(a[h][w]);	
			}	
			for(int j = 0; j < k-1-s; j++) {
				h++;
				e.push_back(a[h][w]);
			}
			ans.push_back(e);
			s++;
		}
		cout << "Yes" << endl;
		for(int i = 0; i < k; i++) {
			cout << k - 1 << ' ';
			for(int j = 0; j < k-1; j++) {
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
}
