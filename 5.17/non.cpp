#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int m = 0;
	int index = 0;
	for(int i = 0; i < n; i++) {
		if(m <= abs(a[i])) {
			m = abs(a[i]);
			index = i;
		}
	}
	vector<P> ans;
	for(int i = 1; i <= n; i++) {
		if(index+1 != i) ans.push_back(P(index+1, i));
	}
	if(a[index] > 0) {
		for(int i = 1; i < n; i++) {
			ans.push_back(P(i, i+1));
		}	
	} else {
		for(int i = n; i >= 2; i--) {
			ans.push_back(P(i, i-1));	
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
