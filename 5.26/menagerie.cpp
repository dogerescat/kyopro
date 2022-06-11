#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n; string s; cin >> n >> s;	
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
		vector<int> a(n);
		a[0] = i; a[1] = j;
		for(int k = 1; k < n-1; k++) {
			if(!a[k]) {
				if(s[k] == 'o') a[k+1] = a[k-1];
				else a[k+1] = 1 - a[k-1];
			} else {
				if(s[k] == 'o') a[k+1] = 1 - a[k-1];
				else a[k+1] = a[k-1];
			}
		}
		bool ok = true;
		for(int k = 0; k < n; k++) {
			if(!a[k]) {
				if(s[k] == 'o' && a[(k+1)%n] != a[(k-1+n)%n]) ok = false;  
				if(s[k] == 'x' && a[(k+1)%n] == a[(k-1+n)%n]) ok = false;
			} else {
				if(s[k] == 'o' && a[(k+1)%n] == a[(k-1+n)%n]) ok = false;
				if(s[k] == 'x' && a[(k+1)%n] != a[(k-1+n)%n]) ok = false;
			}
		}
		if(ok) {
			for(int k = 0; k < n; k++) cout << (!a[k] ? 'S' : 'W');
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
