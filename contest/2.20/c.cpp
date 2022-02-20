#include <iostream>
#include <vector>
using namespace std;

bool f(vector<int> &a, vector<int> &b, vector<vector<int>> &memo, int d, int v) {
	if(d == 0) {
		if(v == 0) return true;
		else return false;
	}
	if(memo[d][v] != -1) return memo[d][v];
	if(v - a[d-1] >= 0) if(f(a, b, memo, d-1, v-a[d-1])) return memo[d][v] = true;
	if(v - b[d-1] >= 0) if(f(a, b, memo, d-1, v-b[d-1])) return memo[d][v] = true;
	return memo[d][v] = 0;
}
int main() {
	int n, x; cin >> n >> x;
	vector<int> a(n), b(n);
	vector<vector<int>> memo(n+1, vector<int> (x+1, -1));
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	if(f(a, b, memo, n, x)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
