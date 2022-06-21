#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;
int main() {
	int n, m; cin >> n >> m;
	vector<int> a(m+2);
	for(int i = 1; i <= m; i++) cin >> a[i];
	a[m+1] = n+1;
	sort(a.begin(), a.end());
	vector<int> diff(m+1);
	int min_diff = INF;
	for(int i = 1; i < m+2; i++) diff[i-1] = a[i] - a[i-1] - 1;
	for(int i = 0; i < m+1; i++) if(diff[i]) min_diff = min(min_diff, diff[i]);
	int ans = 0;
	for(int i = 0; i < m+1; i++) {
		ans += (diff[i] + min_diff - 1) / min_diff;
	}
	cout << ans << endl;
}
