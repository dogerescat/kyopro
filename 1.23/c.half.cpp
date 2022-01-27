#include <iostream>
using namespace std;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if(a + b > 2 * c) {
		ans += 2 * c * min(x, y);	
		if(x > y) x -= y, y = 0;
		else y -= x, x = 0;
		if(a > 2 * c) {
			ans += 2 * c * x;
			x = 0;
		}
		if(b > 2 * c) {
			ans += 2 * c * y;
			y = 0;
		}
	}
	ans += a * x;
	ans += b * y;
	cout << ans << endl;
}
