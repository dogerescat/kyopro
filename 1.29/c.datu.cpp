#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> A(n+1);
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> A[i];
	for(int a = 0; a <= n; a++) {
		for(int b = a; b <= n; b++) {
			for(int c = b; c <= n; c++) {
				for(int d = c; d <= n; d++) {
					int total = A[a] + A[b] + A[c] + A[d];	
					if(total <= m) ans = max(ans, total);
				}
			}
		}
	}	
	cout << ans << endl;
}
