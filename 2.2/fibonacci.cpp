#include <iostream>
#include <vector>
using namespace std;

int f(int v, vector<int> &memo) {
	if(memo[v] != -1) return memo[v];
	int res = f(v-1, memo) + f(v-2, memo);
	return memo[v] = res;
}
int main() {
	int n; cin >> n;
	vector<int> memo(n+1, -1);
	memo[0] = 1, memo[1] = 1;
	cout << f(n, memo) << endl;
}
