#include <iostream>
#include <vector>
using namespace std;
const int M = 300;
double dp[M+4][M+4][M+4];

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> c(4);
	for(int i = 0; i < n; i++) c[a[i]]++;
	for(int k = 0; k <= n; k++) {
		for(int j = 0; j <= n; j++) {
			for(int i = 0; i <= n; i++) {
				int s = i + j + k;
				if(s == 0) continue;
				dp[i][j][k] = 1.0 * n / s;
				if(i) dp[i][j][k] += dp[i-1][j][k] * i / s;
				if(j) dp[i][j][k] += dp[i+1][j-1][k] * j / s;
				if(k) dp[i][j][k] += dp[i][j+1][k-1] * k / s;
			}
		}
	}	
	printf("%.10f\n", dp[c[1]][c[2]][c[3]]);
}
