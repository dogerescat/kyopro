#include <iostream>
using namespace std;

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	bool ok = false;
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	if(x + y == 2) ok = true;
	if(x + y == 4) {
		if(abs(x - y) != 0) ok = true;
	} 
	if(x + y == 6) {
		if(abs(x - y) == 2 || x - y == 0) ok = true;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
