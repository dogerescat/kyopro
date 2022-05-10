#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	while(true) {
		int n, W, D; cin >> n >> W >> D;
		if(!n && !W && !D) break;
		vector<P> A;
		A.push_back(P(W, D));
		for(int i = 0; i < n; i++) {
			int p, s; cin >> p >> s;
			int w = A[p-1].first, d = A[p-1].second;
			A.erase(A.begin()+(p-1));
			int mod = w + d;
			s %= mod;
			if(s <= w) {
				A.push_back(P(min(w-s, s), d));
				A.push_back(P(max(w-s, s), d));
			} else {
				s -= w;
				A.push_back(P(w, min(d-s, s)));
				A.push_back(P(w, max(d-s, s)));
			}
		}
		vector<int> ans;
		for(auto i : A) {
			int S = i.first * i.second;
			ans.push_back(S);
		}	
		sort(ans.begin(), ans.end());	
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1>=ans.size()?"\n":" ");
	}	
	return 0;
}
