#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> A(n+1);
	for(int i = 1; i <= n; i++) cin >> A[i];
	vector<int> B;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			B.push_back(A[i] + A[j]);
		}
	}
	sort(B.begin(), B.end());
	vector<int> C = B;
	int ans = 0;
	for(auto b : B) {
		int left = -1, right = C.size()+1;
		while(right - left > 1) {
			int mid = (left + right) / 2;
			if(C[mid] <= m - b) left = mid;
			else right = mid;
		}
		if(m >= b + C[left]) ans = max(ans, b + C[left]);
	}
	cout << ans << endl;
}
