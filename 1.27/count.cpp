#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> P(n);
	vector<int> Q(n);
	for(int i = 0; i < n; i++) cin >> P[i];
	for(int i = 0; i < n; i++) cin >> Q[i];
	vector<int> A(n);
	iota(A.begin(), A.end(), 1);
	int a, b; 
	int cnt = 0;
	do {
		cnt++;
		if(P == A) a = cnt;
		if(Q == A) b = cnt;
	} while(next_permutation(A.begin(), A.end()));
	int ans = abs(a - b);
	cout << ans << endl;
}
