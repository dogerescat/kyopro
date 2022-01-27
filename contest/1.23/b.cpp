#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n+1);
	for(int i = 0; i < 4 * n - 1; i++) {
		int b; cin >> b;
		a[b]++;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] != 4) {
			cout << i << endl;
			return 0;
		}
	}
}
