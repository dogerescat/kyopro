#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll a, b, k; cin >> a >> b >> k;
	if(a >= k) {
		cout << a - k << ' ' << b << endl;
	} else if(a + b >= k) {
		cout << 0 << ' ' << a + b - k << endl;
	} else {
		cout << 0 << ' ' << 0 << endl;
	}
}
