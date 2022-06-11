#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using P = pair<int, int>;
template<typename T> bool chmax(T& a, T b) {
	if(a <= b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<P> a(n);	
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	vector<int> x(m);
	for(int i = 0; i < m; i++) cin >> x[i];
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		--l, --r;
		vector<int> use_box;
		for(int j = 0; j < m; j++) if(j < l ||  r < j) use_box.push_back(x[j]); 
		sort(use_box.begin(), use_box.end());
		vector<bool> nimotu(n);
		int ans = 0;
		for(int w : use_box) {
			int index = -1;
			int value_max = 0;
			for(int j = 0; j < n; j++) {
				if(w >= a[j].first && !nimotu[j]) {
					if(chmax(value_max, a[j].second)) {
						index = j;	
					}					
				}
			}	
			if(index != -1) {
				nimotu[index] = true;
				ans += value_max;
			}
		}	
		cout << ans << endl;	
	}
}
