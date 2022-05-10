#include <iostream>
using namespace std;

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int takahashi = 0, aoki = 1;
	takahashi += a * 60 * 60;
	takahashi += b * 60;
	aoki += c * 60 * 60;
	aoki += d * 60;
	if(takahashi < aoki) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
}
