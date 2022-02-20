#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int x = abs(a - b);
	if(x == 1 || x == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
}
