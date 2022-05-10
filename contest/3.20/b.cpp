#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, -1, 0, 1};

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int x = 0, y = 0;	
	int a = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'S') {
			x += X[a];	
			y += Y[a];
		} else a = (a + 1) % 4;
	}
	printf("%d %d\n", x, y);
}
