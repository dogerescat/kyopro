#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	vector<vector<char>> ans(100, vector<char> (100, '#'));
	for(int i = 0; i < 100; i++) for(int j = 0; j < 50; j++) ans[i][j] = '.';
	--a, --b;
	for(int i = 0; i < 100; i+=2) {
		for(int j = 0; j < 50; j+=2) {
			if(b > 0) {
				ans[i][j] = '#';
				b--;
			}
		}
	}
	for(int i = 0; i < 100; i+=2) {
		for(int j = 51; j < 100 ; j+=2) {
			if(a > 0) {
				ans[i][j] = '.';
				a--;
			}
		}
	}
	cout << 100 << ' ' << 100 << endl;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
