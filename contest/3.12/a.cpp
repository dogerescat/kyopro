#include <iostream>
using namespace std;

int main() {
	int v, a, b, c; cin >> v >> a >> b >> c;
	while(v >= 0) {
		if(v < a) {
			cout << 'F' << endl;	
			return 0;	
		}
		v -= a;
		if(v < b) {
			cout << 'M' << endl;
			return 0;
		}	
		v -= b;
		if(v < c) {
			cout << 'T' << endl;
			return 0;
		}
		v -= c;
	}
}
