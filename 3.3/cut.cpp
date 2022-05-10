#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	while(true) {
		int n, W, D; cin >> n >> W >> D;
		if(!n && !W && !D) break;
		map<int, P> m;
		m[1].first = W;
		m[1].second = D;
		int M = 1;
		for(int i = 0; i < n; i++) {
			int p, s; cin >> p >> s;
			int w = m[p].first, d = m[p].second;	
			m.erase(p);
			int mod = w + d;
			int a = s % mod;
			int x = w, y = d;
			if(a <= x) {
				x -= a;	
				m[M+1].first = max(x, a);
				m[M+1].second = y;
				m[p].first = min(x, a);
				m[p].second = y;
			} else {
				a -= x;
				y -= a;
				m[M+1].first = x;
				m[M+1].second = max(y, a);
				m[p].first = x;
				m[p].second = min(y, a);
			}
			M++;
		}	
		vector<int> ans;
		for(auto i : m) {
			int S = i.second.first * i.second.second;
			ans.push_back(S);
		}
		sort(ans.begin(), ans.end());	
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1>=ans.size()?"\n":" ");
	}
	return 0;
}
