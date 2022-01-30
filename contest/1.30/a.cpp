#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	ll A = 1LL << 31;
	if(n >= -A && A > n) cout << "Yes" << endl;
	else cout << "No" << endl;
}
