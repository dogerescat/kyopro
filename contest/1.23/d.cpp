#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> a(2*n-1);
	for(int i = 0; i < 2*n-1; i++) {
		for(int j = 0; j < 2*n-1-i; j++) {
			int b; cin >> b;
			a[i].push_back(b);
		}
	}
	
}
