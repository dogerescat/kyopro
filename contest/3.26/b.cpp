#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;	
	vector<bool> a(2010);
	for(int i = 0; i < n; i++) {
		int b; cin >> b;
		a[b] = true;
	}
	for(int i = 0; i <= 2001; i++) {
		if(!a[i]) {
			cout << i << endl;
			return 0;
		}	
	} 
}
