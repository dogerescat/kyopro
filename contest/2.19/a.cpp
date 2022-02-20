#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long;

int main() {
	ll h; cin >> h;
	double ans = sqrt(h * (12800000 + h));
	cout << fixed << setprecision(10) << ans << endl;
}
