#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, z, w; cin >> n >> z >> w;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n == 1) cout << abs(a[n-1]-w) << endl;
	else cout << max(abs(a[n-1]-w), abs(a[n-2]-a[n-1])) << endl;
}
