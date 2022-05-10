#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<P> x;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		x.push_back(P(a, 1));
		x.push_back(P(a+b, -1));
	}
	sort(x.begin(), x.end());
	vector<int> ans(n+1);
	int cnt = 0;
	int prev = 1;
	for(auto p : x) {
		ans[cnt] += p.first - prev;
		cnt += p.second;
		prev = p.first;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
}
