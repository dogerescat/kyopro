#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n, m; cin >> n >> m;
	vector<P> a(m);
	for(int i = 0; i < m; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end());
	int res = 0;
	int curr_right = 0;
	for(int i = 0; i < m; i++) {
		int left = a[i].second;
		int right = a[i].first;
		if(curr_right > left) continue;
		res++;
		curr_right = right;
	}
	cout << res << endl;
}
